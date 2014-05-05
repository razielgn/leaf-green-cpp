#include "message_box_state.hpp"

#include "gtest/gtest.h"
#include "player_input_mock.hpp"

namespace green_leaf {
  using namespace ::testing;

  class MessageBoxStateTest : public Test {
  protected:
    MessageBoxState mbs_;
    PlayerInputMock input_;
  };

  TEST_F(MessageBoxStateTest, New) {
    EXPECT_EQ(0u, mbs_.character());
    EXPECT_EQ(0u, mbs_.line());
    EXPECT_EQ(0u, mbs_.message());
  }

  TEST_F(MessageBoxStateTest, NextLine) {
    mbs_.nextLine();

    EXPECT_EQ(0u, mbs_.character());
    EXPECT_EQ(1u, mbs_.line());
  }

  TEST_F(MessageBoxStateTest, NextMessage) {
    mbs_.nextLine();
    mbs_.nextMessage();

    EXPECT_EQ(0u, mbs_.character());
    EXPECT_EQ(0u, mbs_.line());
    EXPECT_EQ(1u, mbs_.message());
  }

  TEST_F(MessageBoxStateTest, UpdateNormal) {
    EXPECT_CALL(input_, a()).WillRepeatedly(Return(false));
    EXPECT_CALL(input_, b()).WillRepeatedly(Return(false));
    mbs_.update(input_, GameTime(100, 0));

    EXPECT_EQ(1u, mbs_.character());
  }

  TEST_F(MessageBoxStateTest, UpdateFastPressingA) {
    EXPECT_CALL(input_, a()).WillRepeatedly(Return(true));
    EXPECT_CALL(input_, b()).WillRepeatedly(Return(false));
    mbs_.update(input_, GameTime(16, 0));

    EXPECT_EQ(1u, mbs_.character());
  }

  TEST_F(MessageBoxStateTest, UpdateFastPressingB) {
    EXPECT_CALL(input_, a()).WillRepeatedly(Return(false));
    EXPECT_CALL(input_, b()).WillRepeatedly(Return(true));
    mbs_.update(input_, GameTime(16, 0));

    EXPECT_EQ(1u, mbs_.character());
  }
}

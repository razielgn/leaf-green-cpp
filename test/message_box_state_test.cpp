#include "message_box_state.hpp"

#include "gtest/gtest.h"
#include "input_mock.hpp"

namespace green_leaf {
  using namespace ::testing;

  class MessageBoxStateTest : public Test {
  protected:
    MessageBoxState mbs_;
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
    InputMock input;

    EXPECT_CALL(input, isKeyDown(InputKey::A)).WillRepeatedly(Return(false));
    EXPECT_CALL(input, isKeyDown(InputKey::B)).WillRepeatedly(Return(false));
    mbs_.update(input, GameTime(100, 0));

    EXPECT_EQ(1u, mbs_.character());
  }

  TEST_F(MessageBoxStateTest, UpdateFastPressingA) {
    InputMock input;

    EXPECT_CALL(input, isKeyDown(InputKey::A)).WillRepeatedly(Return(true));
    EXPECT_CALL(input, isKeyDown(InputKey::B)).WillRepeatedly(Return(false));
    mbs_.update(input, GameTime(16, 0));

    EXPECT_EQ(1u, mbs_.character());
  }

  TEST_F(MessageBoxStateTest, UpdateFastPressingB) {
    InputMock input;

    EXPECT_CALL(input, isKeyDown(InputKey::A)).WillRepeatedly(Return(false));
    EXPECT_CALL(input, isKeyDown(InputKey::B)).WillRepeatedly(Return(true));
    mbs_.update(input, GameTime(16, 0));

    EXPECT_EQ(1u, mbs_.character());
  }
}

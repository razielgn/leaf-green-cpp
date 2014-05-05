#include "gtest/gtest.h"

#include "content_mock.hpp"
#include "graphics_mock.hpp"
#include "player_input_mock.hpp"
#include "screen_manager.hpp"
#include "screen_mock.hpp"
#include "game_time.hpp"

namespace green_leaf {
  using namespace ::testing;

  class ScreenManagerTest : public Test {
  protected:
    ScreenManagerTest()
      : screen1_(new ScreenMock(screen_manager_))
      , screen2_(new ScreenMock(screen_manager_))
    {
    }

    ContentMock content_;
    ScreenManager screen_manager_ = ScreenManager(content_);
    std::unique_ptr<ScreenMock> screen1_;
    std::unique_ptr<ScreenMock> screen2_;

    PlayerInputMock input_;
    GraphicsMock graphics_;
    const GameTime game_time_ = GameTime(0, 0);
  };

  TEST_F(ScreenManagerTest, CountWhenEmpty) {
    EXPECT_EQ(0u, screen_manager_.count());
  }

  TEST_F(ScreenManagerTest, Push) {
    EXPECT_CALL(*screen1_, loadContent(_)).Times(1);
    screen_manager_.push(std::move(screen1_));

    EXPECT_EQ(1u, screen_manager_.count());
  }

  TEST_F(ScreenManagerTest, Pop) {
    EXPECT_CALL(*screen1_, loadContent(_)).Times(1);
    screen_manager_.push(std::move(screen1_));
    screen_manager_.pop();

    EXPECT_EQ(0u, screen_manager_.count());
  }

  TEST_F(ScreenManagerTest, Update) {
    EXPECT_CALL(*screen1_, loadContent(_)).Times(1);
    EXPECT_CALL(*screen2_, loadContent(_)).Times(1);
    EXPECT_CALL(*screen1_, update(_, _)).Times(0);
    EXPECT_CALL(*screen2_, update(_, _)).Times(1);

    screen_manager_.push(std::move(screen1_));
    screen_manager_.push(std::move(screen2_));
    screen_manager_.update(input_, game_time_);
  }

  TEST_F(ScreenManagerTest, Draw) {
    EXPECT_CALL(*screen1_, loadContent(_)).Times(1);
    EXPECT_CALL(*screen2_, loadContent(_)).Times(1);
    EXPECT_CALL(*screen1_, draw(_)).Times(1);
    EXPECT_CALL(*screen2_, draw(_)).Times(1);

    screen_manager_.push(std::move(screen1_));
    screen_manager_.push(std::move(screen2_));
    screen_manager_.draw(graphics_);
  }
}

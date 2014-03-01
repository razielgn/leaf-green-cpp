#include "gtest/gtest.h"

#include "graphics_mock.hpp"
#include "input_mock.hpp"
#include "screen_manager.hpp"
#include "screen_mock.hpp"
#include "game_time.hpp"

namespace green_leaf {
  using namespace ::testing;

  class ScreenManagerTest : public Test {
  protected:
    ScreenManagerTest() {
    }

    ScreenManager screen_manager_;
  };

  TEST_F(ScreenManagerTest, CountWhenEmpty) {
    EXPECT_EQ(0u, screen_manager_.count());
  }

  TEST_F(ScreenManagerTest, Push) {
    StrictMock<ScreenMock> screen;
    screen_manager_.push(&screen);

    EXPECT_EQ(1u, screen_manager_.count());
  }

  TEST_F(ScreenManagerTest, Pop) {
    StrictMock<ScreenMock> screen;
    screen_manager_.push(&screen);
    screen_manager_.pop();

    EXPECT_EQ(0u, screen_manager_.count());
  }

  TEST_F(ScreenManagerTest, Update) {
    StrictMock<ScreenMock> screen1, screen2;

    InputMock input;
    const GameTime game_time(0, 0);

    EXPECT_CALL(screen1, update(Eq(&input), Eq(&game_time))).Times(0);
    EXPECT_CALL(screen2, update(Eq(&input), Eq(&game_time))).Times(1);

    screen_manager_.push(&screen1);
    screen_manager_.push(&screen2);
    screen_manager_.update(&input, &game_time);
  }

  TEST_F(ScreenManagerTest, Draw) {
    StrictMock<ScreenMock> screen1, screen2;

    GraphicsMock graphics;

    EXPECT_CALL(screen1, draw(Eq(&graphics))).Times(1);
    EXPECT_CALL(screen2, draw(Eq(&graphics))).Times(1);

    screen_manager_.push(&screen1);
    screen_manager_.push(&screen2);
    screen_manager_.draw(&graphics);
  }
}

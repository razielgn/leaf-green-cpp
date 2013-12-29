#include "gtest/gtest.h"
#include "game_time.cpp"

namespace green_leaf {
  class GameTimeTest : public ::testing::Test {
  protected:
    GameTimeTest()
      : game_time_(GameTime(5, 10))
    {
    }

    const GameTime game_time_;
  };

  TEST_F(GameTimeTest, DefaultConstructor) {
    EXPECT_EQ(5u, game_time_.elapsed());
    EXPECT_EQ(10u, game_time_.total());
  }
}

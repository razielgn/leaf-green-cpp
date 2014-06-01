#include "movement_timing.hpp"

#include "game_time.hpp"
#include "gmock/gmock.h"

namespace green_leaf {
  using namespace ::testing;

  class MovementTimingTest : public Test {
  protected:
    MovementTiming mt_;
  };

  TEST_F(MovementTimingTest, ProgressStartsFromZero) {
    EXPECT_FLOAT_EQ(0.0f, mt_.progress());
  }

  TEST_F(MovementTimingTest, UpdateWhenStateIsNotClashingChangesProgress) {
    mt_.clashing(false);
    mt_.update(GameTime(100, 0));

    EXPECT_NEAR(0.4, mt_.progress(), 0.01);
  }

  TEST_F(MovementTimingTest, UpdateWhenStateIsClashingChangesProgress) {
    mt_.clashing(true);
    mt_.update(GameTime(100, 0));

    EXPECT_NEAR(0.2, mt_.progress(), 0.01);
  }

  TEST_F(MovementTimingTest, UpdateWhenTurningChangesProgress) {
    mt_.turning(true);
    mt_.update(GameTime(100, 0));

    EXPECT_NEAR(0.66, mt_.progress(), 0.01);
  }

  TEST_F(MovementTimingTest, UpdateFinishingAnAnimationGetsToOne) {
    mt_.update(GameTime(250, 0));

    EXPECT_NEAR(1.0, mt_.progress(), 0.01);
  }

  TEST_F(MovementTimingTest, FinishedReturnsTrueWhenAnimationIsComplete) {
    mt_.update(GameTime(250, 0));

    EXPECT_TRUE(mt_.finished());
  }

  TEST_F(MovementTimingTest, FinishedReturnsFalseWhenAnimationIsInProgress) {
    mt_.update(GameTime(100, 0));

    EXPECT_FALSE(mt_.finished());
  }
}

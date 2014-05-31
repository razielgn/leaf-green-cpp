#include "player_movement.hpp"

#include "direction.hpp"
#include "game_time.hpp"
#include "gmock/gmock.h"
#include "player_input_mock.hpp"

namespace green_leaf {
  using namespace ::testing;

#define KEY_STATUS(button, status) EXPECT_CALL(input_, button()).WillRepeatedly(Return(status));
#define KEY_PRESSED(button)        KEY_STATUS(button, true);
#define KEY_NOT_PRESSED(button)    KEY_STATUS(button, false);

  class PlayerMovementTest : public Test {
  protected:
    PlayerMovementTest()
      : pm_(Direction::Down)
    {
    }

    void SetUp() {
      nothingPressed();
    }

    void nothingPressed() {
      KEY_NOT_PRESSED(up);
      KEY_NOT_PRESSED(down);
      KEY_NOT_PRESSED(left);
      KEY_NOT_PRESSED(right);
    }

    PlayerMovement pm_;
    PlayerInputMock input_;
  };

  TEST_F(PlayerMovementTest, DirectionIsTakenAsParameter) {
    EXPECT_EQ(Direction::Down, pm_.direction());
  }

  TEST_F(PlayerMovementTest, StateDefaultsToIdle) {
    EXPECT_EQ(MovementState::Idle, pm_.state());
  }

  TEST_F(PlayerMovementTest, UpdateSetsDirectionToRight) {
    KEY_PRESSED(right);

    pm_.update(input_);

    EXPECT_EQ(Direction::Right, pm_.direction());
  }

  TEST_F(PlayerMovementTest, UpdateSetsDirectionToLeft) {
    KEY_PRESSED(left);

    pm_.update(input_);

    EXPECT_EQ(Direction::Left, pm_.direction());
  }

  TEST_F(PlayerMovementTest, UpdateSetsDirectionToDown) {
    KEY_PRESSED(down);

    pm_.update(input_);

    EXPECT_EQ(Direction::Down, pm_.direction());
  }

  TEST_F(PlayerMovementTest, UpdateSetsDirectionToUp) {
    KEY_PRESSED(up);

    pm_.update(input_);

    EXPECT_EQ(Direction::Up, pm_.direction());
  }

  TEST_F(PlayerMovementTest, UpdateSetsStateToIdleWhenNothingIsPressed) {
    KEY_PRESSED(up);
    pm_.update(input_);
    nothingPressed();

    pm_.update(input_);

    EXPECT_EQ(MovementState::Idle, pm_.state());
  }

  TEST_F(PlayerMovementTest, UpdateSetsStateToTurningWhenChangingDirectionOfMovement) {
    KEY_PRESSED(up);

    pm_.update(input_);

    EXPECT_EQ(MovementState::Turning, pm_.state());
  }

  TEST_F(PlayerMovementTest, UpdateSetsStateToMovingWhenGoingInTheSameDirection) {
    KEY_PRESSED(down);

    pm_.update(input_);

    EXPECT_EQ(MovementState::Moving, pm_.state());
  }

  TEST_F(PlayerMovementTest, ResetSetsStateToIdle) {
    KEY_PRESSED(down);
    pm_.update(input_);

    pm_.reset();

    EXPECT_EQ(MovementState::Idle, pm_.state());
  }

#undef KEY_STATUS
#undef KEY_PRESSED
#undef KEY_NOT_PRESSED
}

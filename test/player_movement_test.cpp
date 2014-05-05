#include "player_movement.hpp"

#include "game_time.hpp"
#include "gmock/gmock.h"
#include "movement.hpp"
#include "player_input_mock.hpp"

namespace green_leaf {
  using namespace ::testing;

#define KEY_STATUS(button, status) \
  EXPECT_CALL(input_, button()).WillRepeatedly(Return(status));
#define KEY_PRESSED(button) \
  KEY_STATUS(button, true);
#define KEY_NOT_PRESSED(button) \
  KEY_STATUS(button, false);

  class PlayerMovementTest : public Test {
  protected:
    PlayerMovementTest() { }

    void SetUp() {
      nothingPressed();
    }

    void nothingPressed() {
      KEY_NOT_PRESSED(a);
      KEY_NOT_PRESSED(b);
      KEY_NOT_PRESSED(up);
      KEY_NOT_PRESSED(down);
      KEY_NOT_PRESSED(left);
      KEY_NOT_PRESSED(right);
      KEY_NOT_PRESSED(start);
      KEY_NOT_PRESSED(select);
      KEY_NOT_PRESSED(l);
      KEY_NOT_PRESSED(r);
      KEY_NOT_PRESSED(escape);
    }

    PlayerMovement player_movement_ = PlayerMovement(Movement::Down);
    PlayerInputMock input_;

    const GameTime empty_anim_ = GameTime(0, 0);
    const GameTime half_anim_ = GameTime(125, 0);
    const GameTime full_anim_ = GameTime(250, 0);
  };

  TEST_F(PlayerMovementTest, Constructor) {
    EXPECT_EQ(Movement::Down, player_movement_.direction());
  }

  TEST_F(PlayerMovementTest, DownKeyPressed) {
    KEY_PRESSED(down);

    player_movement_.update(input_, half_anim_);

    EXPECT_TRUE(player_movement_.moving());
    EXPECT_EQ(Movement::Down, player_movement_.movement());
  }

  TEST_F(PlayerMovementTest, RightKeyPressed) {
    KEY_PRESSED(right);

    player_movement_.update(input_, half_anim_);

    EXPECT_TRUE(player_movement_.moving());
    EXPECT_EQ(Movement::Right, player_movement_.movement());
  }

  TEST_F(PlayerMovementTest, LeftKeyPressed) {
    KEY_PRESSED(left);

    player_movement_.update(input_, half_anim_);

    EXPECT_TRUE(player_movement_.moving());
    EXPECT_EQ(Movement::Left, player_movement_.movement());
  }

  TEST_F(PlayerMovementTest, UpKeyPressed) {
    KEY_PRESSED(up);

    player_movement_.update(input_, half_anim_);

    EXPECT_TRUE(player_movement_.moving());
    EXPECT_EQ(Movement::Up, player_movement_.movement());
  }

  TEST_F(PlayerMovementTest, InputSkippedWhenMoving) {
    KEY_PRESSED(up);

    player_movement_.update(input_, half_anim_);

    EXPECT_TRUE(player_movement_.moving());
    EXPECT_EQ(Movement::Up, player_movement_.movement());

    nothingPressed();

    player_movement_.update(input_, half_anim_);

    EXPECT_TRUE(player_movement_.moving());
    EXPECT_EQ(Movement::Up, player_movement_.movement());
  }

  TEST_F(PlayerMovementTest, ProgressFrozenWhenStill) {
    nothingPressed();

    player_movement_.update(input_, half_anim_);

    EXPECT_FLOAT_EQ(0.0f, player_movement_.progress());
  }

  TEST_F(PlayerMovementTest, AnimationProgress) {
    KEY_PRESSED(down);

    int elapsed = 0;
    float progress = 0.0f;

    do {
      player_movement_.update(input_, GameTime(elapsed, 0));

      EXPECT_FLOAT_EQ(progress, player_movement_.progress());

      progress += 0.2f;
      elapsed = 50;
    } while(progress <= 1.0f);
  }

  TEST_F(PlayerMovementTest, Finished) {
    KEY_PRESSED(down);

    player_movement_.update(input_, full_anim_);
    EXPECT_TRUE(player_movement_.finished());
  }

  TEST_F(PlayerMovementTest, MovementIsResetAfterFinish) {
    KEY_PRESSED(down);

    player_movement_.update(input_, full_anim_);

    nothingPressed();

    player_movement_.update(input_, empty_anim_);

    EXPECT_EQ(Movement::Still, player_movement_.movement());
  }

  TEST_F(PlayerMovementTest, DirectionIsMovementAfterFinish) {
    KEY_PRESSED(down);

    player_movement_.update(input_, full_anim_);

    nothingPressed();

    player_movement_.update(input_, empty_anim_);

    EXPECT_EQ(Movement::Down, player_movement_.direction());
  }

  TEST_F(PlayerMovementTest, ResetStateAfterFinished) {
    KEY_PRESSED(down);

    player_movement_.update(input_, full_anim_);
    EXPECT_TRUE(player_movement_.finished());
    EXPECT_TRUE(player_movement_.moving());
    EXPECT_FLOAT_EQ(1.0f, player_movement_.progress());

    nothingPressed();

    player_movement_.update(input_, half_anim_);
    EXPECT_FALSE(player_movement_.finished());
    EXPECT_FALSE(player_movement_.moving());
    EXPECT_THAT(0.0f, player_movement_.progress());
  }

  TEST_F(PlayerMovementTest, Clashing) {
    player_movement_.clashing(true);
    EXPECT_TRUE(player_movement_.clashing());

    player_movement_.clashing(false);
    EXPECT_FALSE(player_movement_.clashing());
  }

  TEST_F(PlayerMovementTest, WalkingAndClashing) {
    KEY_PRESSED(down);
    player_movement_.clashing(true);

    player_movement_.update(input_, full_anim_);
    EXPECT_FALSE(player_movement_.finished());
    EXPECT_TRUE(player_movement_.moving());
    EXPECT_TRUE(player_movement_.clashing());
    EXPECT_FLOAT_EQ(0.5f, player_movement_.progress());

    player_movement_.update(input_, full_anim_);
    EXPECT_TRUE(player_movement_.finished());
    EXPECT_TRUE(player_movement_.moving());
    EXPECT_TRUE(player_movement_.clashing());
    EXPECT_FLOAT_EQ(1.0f, player_movement_.progress());
  }

#undef KEY_STATUS
#undef KEY_PRESSED
#undef KEY_NOT_PRESSED
}

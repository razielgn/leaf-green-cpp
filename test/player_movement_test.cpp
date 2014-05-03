#include "gmock/gmock.h"
#include "movement.hpp"
#include "player_movement.hpp"
#include "game_time.hpp"

#include "input_mock.hpp"

namespace green_leaf {
  using namespace ::testing;

  class PlayerMovementTest : public Test {
  protected:
    PlayerMovementTest() { }

    void onlyPressed(InputKey key) {
      EXPECT_CALL(input_, isKeyDown(key)).WillRepeatedly(Return(true));
      EXPECT_CALL(input_, isKeyDown(Ne(key))).WillRepeatedly(Return(false));
    }

    void nothingPressed() {
      EXPECT_CALL(input_, isKeyDown(_)).WillRepeatedly(Return(false));
    }

    PlayerMovement player_movement_ = PlayerMovement(Movement::Down);
    InputMock input_;

    const GameTime empty_anim_ = GameTime(0, 0);
    const GameTime half_anim_ = GameTime(125, 0);
    const GameTime full_anim_ = GameTime(250, 0);
  };

  TEST_F(PlayerMovementTest, Constructor) {
    EXPECT_EQ(Movement::Down, player_movement_.direction());
  }

  TEST_F(PlayerMovementTest, DownKeyPressed) {
    onlyPressed(InputKey::Down);

    player_movement_.update(input_, half_anim_);

    EXPECT_TRUE(player_movement_.moving());
    EXPECT_EQ(Movement::Down, player_movement_.movement());
  }

  TEST_F(PlayerMovementTest, RightKeyPressed) {
    onlyPressed(InputKey::Right);

    player_movement_.update(input_, half_anim_);

    EXPECT_TRUE(player_movement_.moving());
    EXPECT_EQ(Movement::Right, player_movement_.movement());
  }

  TEST_F(PlayerMovementTest, LeftKeyPressed) {
    onlyPressed(InputKey::Left);

    player_movement_.update(input_, half_anim_);

    EXPECT_TRUE(player_movement_.moving());
    EXPECT_EQ(Movement::Left, player_movement_.movement());
  }

  TEST_F(PlayerMovementTest, UpKeyPressed) {
    onlyPressed(InputKey::Up);

    player_movement_.update(input_, half_anim_);

    EXPECT_TRUE(player_movement_.moving());
    EXPECT_EQ(Movement::Up, player_movement_.movement());
  }

  TEST_F(PlayerMovementTest, InputSkippedWhenMoving) {
    onlyPressed(InputKey::Up);

    player_movement_.update(input_, half_anim_);

    EXPECT_TRUE(player_movement_.moving());
    EXPECT_EQ(Movement::Up, player_movement_.movement());

    onlyPressed(InputKey::Down);

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
    onlyPressed(InputKey::Down);

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
    onlyPressed(InputKey::Down);

    player_movement_.update(input_, full_anim_);
    EXPECT_TRUE(player_movement_.finished());
  }

  TEST_F(PlayerMovementTest, MovementIsResetAfterFinish) {
    onlyPressed(InputKey::Down);
    player_movement_.update(input_, full_anim_);
    nothingPressed();
    player_movement_.update(input_, empty_anim_);

    EXPECT_EQ(Movement::Still, player_movement_.movement());
  }

  TEST_F(PlayerMovementTest, DirectionIsMovementAfterFinish) {
    onlyPressed(InputKey::Down);
    player_movement_.update(input_, full_anim_);
    nothingPressed();
    player_movement_.update(input_, empty_anim_);

    EXPECT_EQ(Movement::Down, player_movement_.direction());
  }

  TEST_F(PlayerMovementTest, ResetStateAfterFinished) {
    onlyPressed(InputKey::Down);

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
    onlyPressed(InputKey::Down);
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
}

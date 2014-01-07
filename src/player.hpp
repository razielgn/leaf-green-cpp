#ifndef GL_PLAYER_HPP
#define GL_PLAYER_HPP

#include "vector2.hpp"

namespace green_leaf {
  class GameTime;
  class Graphics;
  class Input;
  class PlayerMovement;
  class Texture;

  class Player {
  public:
    Player();
    void loadContent(Graphics* graphics);
    void unloadContent();

    void update(Input* input, GameTime* game_time, PlayerMovement* player_movement);
    void draw(Graphics* graphics);

  private:
    Texture* texture_;

    Vector2 frame_;
    int a_;
    const Vector2 frame_size_ = Vector2(16, 20);
  };
}

#endif

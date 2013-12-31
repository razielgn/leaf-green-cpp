#ifndef GL_PLAYER_HPP
#define GL_PLAYER_HPP

#include "point.hpp"

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

    Point frame_;
    int a_;
    const int frame_w = 16;
    const int frame_h = 20;
  };
}

#endif

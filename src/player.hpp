#ifndef GL_PLAYER_HPP
#define GL_PLAYER_HPP

#include "vector2.hpp"

namespace green_leaf {
  class Content;
  class GameTime;
  class Graphics;
  class Input;
  class PlayerMovement;
  class Texture;

  class Player {
  public:
    Player();
    void loadContent(const Content* graphics);
    void unloadContent();

    void update(const PlayerMovement* player_movement);
    void draw(const Graphics* graphics) const;

  private:
    const Texture* texture_;

    Vector2 frame_;
    int a_;
    const Vector2 frame_size_ = Vector2(16, 20);
  };
}

#endif

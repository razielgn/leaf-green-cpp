#ifndef GL_PLAYER_HPP
#define GL_PLAYER_HPP

#include "texture.hpp"
#include "vector2.hpp"

#include <memory>

namespace green_leaf {
  class Content;
  class GameTime;
  class Graphics;
  class Input;
  class PlayerMovement;

  class Player {
  public:
    Player();
    void loadContent(const Content& graphics);

    void update(const PlayerMovement& player_movement);
    void draw(const Graphics& graphics) const;

  private:
    std::unique_ptr<const Texture> texture_;

    Vector2 frame_;
    unsigned int alternate_walk_;
    const Vector2 frame_size_ = Vector2(16, 20);
  };
}

#endif

#pragma once
#ifndef GL_PLAYER_ANIMATION_HPP
#define GL_PLAYER_ANIMATION_HPP

#include "texture.hpp"
#include "vector2.hpp"

#include <memory>

namespace green_leaf {
  class Content;
  class Graphics;
  class PlayerMovement;
  enum class Direction;

  enum class AlternateMovement {
    Right,
    Left
  };

  class PlayerAnimation {
  public:
    PlayerAnimation(const Direction direction);

    void loadContent(const Content& content);
    void update(const PlayerMovement& player_movement);
    void draw(const Graphics& graphics) const;

  private:
    std::unique_ptr<const Texture> texture_;
    Vector2 frame_;
    AlternateMovement alternate_movement_;
  };
}

#endif

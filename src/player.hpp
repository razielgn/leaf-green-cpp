#pragma once
#ifndef GL_PLAYER_HPP
#define GL_PLAYER_HPP

#include "texture.hpp"
#include "vector2.hpp"

#include <memory>

namespace green_leaf {
  class Content;
  class Graphics;
  enum class Direction;
  class PlayerMovement;

  enum class AlternateMovement {
    Right,
    Left
  };

  class Player {
  public:
    Player(const Direction direction);

    void loadContent(const Content& content);
    void update(const PlayerMovement& player_movement, const Vector2 position);
    void draw(const Graphics& graphics) const;

  private:
    std::unique_ptr<const Texture> texture_;
    Vector2 frame_;
    Vector2 position_;
    AlternateMovement alternate_movement_;
  };
}

#endif

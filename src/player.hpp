#pragma once
#ifndef GL_PLAYER_HPP
#define GL_PLAYER_HPP

#include "texture.hpp"
#include "vector2.hpp"

#include <memory>

namespace green_leaf {
  class Content;
  class Graphics;
  class MovementTiming;
  class PlayerMovement;
  enum class Direction;

  enum class AlternateMovement {
    Right,
    Left
  };

  class Player {
  public:
    Player(const Direction direction);

    void loadContent(const Content& content);
    void update(const PlayerMovement& player_movement, const MovementTiming& timing);
    void draw(const Graphics& graphics) const;

    void position(const Vector2 position) {
      position_ = position;
    }

  private:
    std::unique_ptr<const Texture> texture_;
    Vector2 frame_;
    Vector2 position_;
    AlternateMovement alternate_movement_;
  };
}

#endif

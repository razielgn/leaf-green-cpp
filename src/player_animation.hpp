#ifndef GL_PLAYER_ANIMATION_HPP
#define GL_PLAYER_ANIMATION_HPP

#include "texture.hpp"
#include "vector2.hpp"

#include <memory>

namespace green_leaf {
  class Content;
  class Graphics;
  class PlayerInput;
  class PlayerMovement;

  enum AlternateMovement {
    Right,
    Left
  };

  class PlayerAnimation {
  public:
    PlayerAnimation();

    void loadContent(const Content& content);
    void update(const PlayerMovement& player_movement);
    void draw(const Graphics& graphics) const;

  private:
    const Vector2 frame_size_ = Vector2(16, 20);

    std::unique_ptr<const Texture> texture_;
    Vector2 frame_;
    AlternateMovement alternate_movement_;

    void alternateMovement();
    float animationProgress(bool clashing) const;
    Vector2 nextAnimationFrame() const;
    Vector2 stillAnimationFrame() const;
  };
}

#endif

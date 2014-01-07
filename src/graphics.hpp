#ifndef GL_GRAPHICS_HPP
#define GL_GRAPHICS_HPP

#include <SDL.h>
#include "vector2.hpp"

namespace green_leaf {
  class Rectangle;
  class Texture;

  class Graphics {
  public:
    Graphics(bool visible = true);
    ~Graphics();

    void clear();
    void drawTexture(const Texture* texture, const Rectangle* destination, const Rectangle* source);
    void drawTexture(const Texture* texture, const Rectangle* destination);
    void present();

    SDL_Renderer* renderer() const {
      return renderer_;
    }

    Vector2 size() const {
      return size_;
    }

  private:
    SDL_Window* window_;
    SDL_Renderer* renderer_;

    const Vector2 size_ = Vector2(240, 160);
    int scale_ = 4;
  };
}

#endif

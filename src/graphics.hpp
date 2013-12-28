#ifndef GL_GRAPHICS_HPP
#define GL_GRAPHICS_HPP

#include <SDL.h>

namespace green_leaf {
  class Rectangle;
  class Texture;

  class Graphics {
  public:
    Graphics();
    ~Graphics();

    void clear();
    void drawTexture(const Texture* texture, const Rectangle* destination, const Rectangle* source);
    void drawTexture(const Texture* texture, const Rectangle* destination);
    void present();

    SDL_Renderer* renderer() const {
      return renderer_;
    }

    int width() const {
      return width_;
    }

    int height() const {
      return height_;
    }

  private:
    SDL_Window* window_;
    SDL_Renderer* renderer_;

    int width_ = 240;
    int height_ = 160;
    int scale_ = 1;
  };
}

#endif

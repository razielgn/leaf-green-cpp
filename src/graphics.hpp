#ifndef GL_GRAPHICS_HPP
#define GL_GRAPHICS_HPP

#include <SDL.h>

namespace green_leaf {
  class Texture;

  class Graphics {
  public:
    Graphics();
    ~Graphics();

    void clear();
    void drawTexture(Texture* texture, SDL_Rect* source, SDL_Rect* dest);
    void present();

    SDL_Renderer* renderer() const {
      return renderer_;
    }

  private:
    SDL_Window* window_;
    SDL_Renderer* renderer_;
  };
}

#endif

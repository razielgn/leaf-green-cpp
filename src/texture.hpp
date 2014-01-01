#ifndef GL_TEXTURE_CPP
#define GL_TEXTURE_CPP

#include <SDL.h>

#include "point.hpp"

namespace green_leaf {
  class Graphics;

  class Texture {
  public:
    static Texture* fromPath(const Graphics* graphics, const char* path);

    Texture(Point size);
    ~Texture();

    SDL_Texture* toSDLTexture() const {
      return texture_;
    }

    Point size() const {
      return size_;
    }

  private:
    SDL_Texture* texture_;

    Point size_;

    void loadSDLTexture(SDL_Texture* data);
  };
}

#endif

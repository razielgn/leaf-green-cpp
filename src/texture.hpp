#ifndef GL_TEXTURE_CPP
#define GL_TEXTURE_CPP

#include <SDL.h>

#include "vector2.hpp"

namespace green_leaf {
  class Graphics;

  class Texture {
  public:
    static Texture* fromPath(const Graphics* graphics, const char* path);

    Texture(Vector2 size);
    ~Texture();

    SDL_Texture* toSDLTexture() const {
      return texture_;
    }

    Vector2 size() const {
      return size_;
    }

  private:
    SDL_Texture* texture_;

    Vector2 size_;

    void loadSDLTexture(SDL_Texture* data);
  };
}

#endif

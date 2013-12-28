#ifndef GL_TEXTURE_CPP
#define GL_TEXTURE_CPP

#include <SDL.h>

namespace green_leaf {
  class Graphics;

  class Texture {
  public:
    static Texture* fromPath(const Graphics* graphics, const char* path);
    ~Texture();

    SDL_Texture* data() const {
      return texture_;
    }

  private:
    SDL_Texture* texture_;
  };
}

#endif

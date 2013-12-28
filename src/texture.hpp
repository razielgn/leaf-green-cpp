#ifndef GL_TEXTURE_CPP
#define GL_TEXTURE_CPP

#include <SDL.h>

namespace green_leaf {
  class Graphics;

  class Texture {
  public:
    static Texture* fromPath(const Graphics* graphics, const char* path);
    ~Texture();

    SDL_Texture* toSDLTexture() const {
      return texture_;
    }

    int width() const {
      return width_;
    }

    int height() const {
      return height_;
    }

  private:
    SDL_Texture* texture_;

    int width_;
    int height_;

    void fromSDLTexture(SDL_Texture* data);
  };
}

#endif

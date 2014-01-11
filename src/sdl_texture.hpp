#ifndef GL_SDL_TEXTURE_CPP
#define GL_SDL_TEXTURE_CPP

#include <SDL.h>

#include "texture.hpp"

namespace green_leaf {
  class Graphics;

  class SDLTexture : public Texture {
  public:
    static SDLTexture* fromPath(const Graphics* graphics_, const char* path);

    ~SDLTexture();

    SDL_Texture* data() const {
      return data_;
    }

    Vector2 size() const {
      return size_;
    }

  private:
    SDL_Texture* data_;

    Vector2 size_;

    SDLTexture(Vector2 size);
    void loadData(SDL_Texture* data);
  };
}

#endif

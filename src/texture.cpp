#include "texture.hpp"
#include "graphics.hpp"

#include <SDL.h>
#include <SDL_image.h>

namespace green_leaf {
  Vector2 fetchTextureSize(SDL_Texture* texture) {
    int width = 0, height = 0;
    int return_value = SDL_QueryTexture(texture, NULL, NULL, &width, &height);

    if(return_value != 0) {
      throw "Could not extract width and height from texture.";
    }

    return Vector2(width, height);
  }

  Texture* Texture::fromPath(const Graphics* graphics, const char* path) {
    SDL_Surface* surface = IMG_Load(path);
    if (!surface) { throw "Could not load image"; }

    SDL_Texture* sdl_texture = SDL_CreateTextureFromSurface(graphics->renderer(), surface);
    if (!sdl_texture) { throw "Could create texture from file"; }

    Vector2 textureSize = fetchTextureSize(sdl_texture);

    Texture* texture = new Texture(textureSize);
    texture->loadSDLTexture(sdl_texture);

    SDL_FreeSurface(surface);

    return texture;
  }

  Texture::Texture(Vector2 size)
    : texture_(nullptr)
    , size_(size)
  {
  }

  void Texture::loadSDLTexture(SDL_Texture* data) {
    texture_ = data;
  }

  Texture::~Texture() {
    if(texture_ != nullptr) {
      SDL_DestroyTexture(texture_);
    }
  }
}

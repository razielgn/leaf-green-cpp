#include "texture.hpp"
#include "graphics.hpp"

#include <SDL.h>
#include <SDL_image.h>

namespace green_leaf {
  Texture* Texture::fromPath(const Graphics* graphics, const char* path) {
    Texture* texture = new Texture();

    SDL_Surface* surface = IMG_Load(path);
    if (!surface) { throw "Could not load image"; }

    SDL_Texture* sdl_texture = SDL_CreateTextureFromSurface(graphics->renderer(), surface);
    if (!sdl_texture) { throw "Could create texture from file"; }

    texture->fromSDLTexture(sdl_texture);

    SDL_FreeSurface(surface);

    return texture;
  }

  void fillTextureMetadata(SDL_Texture* texture, int* width, int* height) {
    int return_value = SDL_QueryTexture(texture, NULL, NULL, width, height);

    if(return_value != 0) {
      throw "Could not extract width and height from texture.";
    }
  }

  void Texture::fromSDLTexture(SDL_Texture* data) {
    texture_ = data;

    fillTextureMetadata(data, &width_, &height_);
  }

  Texture::~Texture() {
    SDL_DestroyTexture(texture_);
  }
}

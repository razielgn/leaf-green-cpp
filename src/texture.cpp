#include "texture.hpp"
#include "graphics.hpp"

namespace green_leaf {
  Texture* Texture::from_path(const Graphics* graphics, const char* path) {
    Texture* texture = new Texture();

    SDL_Surface* surface = IMG_Load(path);
    if (!surface) { throw "Could not load image"; }

    texture->texture_ = SDL_CreateTextureFromSurface(graphics->renderer(), surface);
    if (!texture->texture_) { throw "Could create texture from file"; }

    SDL_FreeSurface(surface);

    return texture;
  }

  Texture::~Texture() {
    SDL_DestroyTexture(texture_);
  }
}

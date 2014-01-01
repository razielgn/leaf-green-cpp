#include "graphics.hpp"
#include "rectangle.hpp"
#include "texture.hpp"

namespace green_leaf {
  Graphics::Graphics() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
      throw "Could not initialize SDL system";
    }

    window_ = SDL_CreateWindow("Pokémon GreenLeaf - The Remake!",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               width_ * scale_,
                               height_ * scale_,
                               SDL_WINDOW_SHOWN);

    if(!window_) {
      throw "Could not create SDL window";
    }

    renderer_ = SDL_CreateRenderer(window_,
                                   -1,
                                   SDL_RENDERER_ACCELERATED |
                                   SDL_RENDERER_PRESENTVSYNC);
  }

  Graphics::~Graphics() {
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
    SDL_Quit();
  }

  void Graphics::clear() {
    SDL_RenderClear(renderer_);
  }

  void Graphics::drawTexture(const Texture* texture, const Rectangle* destination, const Rectangle* source) {
    Rectangle scaled_destination = destination->scale(scale_);

    const SDL_Rect source_rect = source->toSDLRect();
    const SDL_Rect dest_rect   = scaled_destination.toSDLRect();

    SDL_RenderCopy(renderer_, texture->toSDLTexture(), &source_rect, &dest_rect);
  }

  void Graphics::drawTexture(const Texture* texture, const Rectangle* destination) {
    Rectangle source(0, 0, texture->size());

    drawTexture(texture, destination, &source);
  }

  void Graphics::present() {
    SDL_RenderPresent(renderer_);
  }
}

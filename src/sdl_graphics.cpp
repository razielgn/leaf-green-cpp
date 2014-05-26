#include "sdl_graphics.hpp"

#include "rectangle.hpp"
#include "sdl_texture.hpp"

namespace green_leaf {
  SDLGraphics::SDLGraphics(unsigned int scale)
    : scale_(scale)
    , size_(240, 160)
  {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
      throw "Could not initialize SDL video system";
    }

    window_ = SDL_CreateWindow("Pokémon GreenLeaf - The Remake!",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               size_.x() * scale_,
                               size_.y() * scale_,
                               SDL_WINDOW_SHOWN);

    if(!window_) {
      throw "Could not create SDL window";
    }

    renderer_ = SDL_CreateRenderer(window_,
                                   -1,
                                   SDL_RENDERER_ACCELERATED |
                                   SDL_RENDERER_PRESENTVSYNC);
  }

  SDLGraphics::~SDLGraphics() {
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
    SDL_Quit();
  }

  void SDLGraphics::clear() const {
    SDL_RenderClear(renderer_);
  }

  void SDLGraphics::drawTexture(const Texture& texture_, const Rectangle destination, const Rectangle source) const {
    const SDLTexture& texture = static_cast<const SDLTexture&>(texture_);

    Rectangle scaled_destination = destination * scale_;

    const SDL_Rect source_rect = source.toSDLRect();
    const SDL_Rect dest_rect   = scaled_destination.toSDLRect();

    SDL_RenderCopy(renderer_, &texture.data(), &source_rect, &dest_rect);
  }

  void SDLGraphics::drawTexture(const Texture& texture, const Rectangle destination) const {
    Rectangle source(0, 0, texture.size());

    drawTexture(texture, destination, source);
  }

  void SDLGraphics::drawTexture(const Texture& texture, const Vector2 offset, const Rectangle source) const {
    drawTexture(texture, Rectangle(offset, source.size()), source);
  }

  void SDLGraphics::present() const {
    SDL_RenderPresent(renderer_);
  }
}

#ifndef GL_SDL_INPUT_HPP
#define GL_SDL_INPUT_HPP

#include <SDL.h>
#include "input.hpp"

namespace green_leaf {
  class SDLInput : public Input {
  public:
    ~SDLInput();
    void recordState();

    bool hasQuit();
    bool isKeyUp(InputKey key);
    bool isKeyDown(InputKey key);

  private:
    SDL_Event event_;
    const Uint8* keyboard_state_;
  };
}

#endif

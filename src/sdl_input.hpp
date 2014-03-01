#ifndef GL_SDL_INPUT_HPP
#define GL_SDL_INPUT_HPP

#include "input.hpp"

#include <SDL_events.h>
#include <SDL_keycode.h>

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

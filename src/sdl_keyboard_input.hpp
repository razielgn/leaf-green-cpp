#ifndef GL_SDL_KEYBOARD_INPUT_HPP
#define GL_SDL_KEYBOARD_INPUT_HPP

#include "keyboard_input.hpp"

#include <SDL_events.h>
#include <SDL_keycode.h>

namespace green_leaf {
  class SDLKeyboardInput : public KeyboardInput {
  public:
    ~SDLKeyboardInput();
    void recordState();

    bool isKeyUp(InputKey key);
    bool isKeyDown(InputKey key);

  private:
    SDL_Event event_;
    const Uint8* keyboard_state_;
  };
}

#endif

#pragma once
#ifndef GL_SDL_KEYBOARD_INPUT_HPP
#define GL_SDL_KEYBOARD_INPUT_HPP

#include "keyboard_input.hpp"

#include <SDL_stdinc.h>

namespace green_leaf {
  class SDLKeyboardInput : public KeyboardInput {
  public:
    void recordState();

    bool isKeyUp(InputKey key);
    bool isKeyDown(InputKey key);

  private:
    const Uint8* keyboard_state_;
  };
}

#endif

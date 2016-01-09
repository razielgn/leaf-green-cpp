#pragma once

#include "keyboard_input.hpp"

#include <SDL_stdinc.h>

namespace green_leaf {
  class SDLKeyboardInput : public KeyboardInput {
  public:
    void recordState() override;

    bool isKeyUp(InputKey key) const override;
    bool isKeyDown(InputKey key) const override;

  private:
    const Uint8* keyboard_state_;
  };
}

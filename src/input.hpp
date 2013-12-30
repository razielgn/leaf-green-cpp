#ifndef GL_INPUT_HPP
#define GL_INPUT_HPP

#include <SDL.h>
#include "input_key.hpp"

namespace green_leaf {
  class Input {
  public:
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

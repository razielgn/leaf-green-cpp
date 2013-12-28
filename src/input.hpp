#ifndef GL_INPUT_HPP
#define GL_INPUT_HPP

#include <SDL.h>

namespace green_leaf {
  enum Keys {
    A,
    B,
    Up,
    Down,
    Left,
    Right,
    Start,
    Select,
    R,
    L,
    Escape,
  };

  class Input {
  public:
    void recordState();

    bool hasQuit();
    bool isKeyUp(Keys key);
    bool isKeyDown(Keys key);

  private:
    SDL_Event event_;
    const Uint8* keyboard_state_;
  };
}

#endif

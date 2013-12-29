#include "input.hpp"

namespace green_leaf {
  void Input::recordState() {
    keyboard_state_ = SDL_GetKeyboardState(NULL);
    SDL_PollEvent(&event_);
  }

  SDL_Scancode convertKeyToScancode(Keys key) {
    switch(key) {
      case A:       return SDL_SCANCODE_X;
      case B:       return SDL_SCANCODE_Z;
      case Up:      return SDL_SCANCODE_UP;
      case Down:    return SDL_SCANCODE_DOWN;
      case Left:    return SDL_SCANCODE_LEFT;
      case Right:   return SDL_SCANCODE_RIGHT;
      case Start:   return SDL_SCANCODE_RETURN;
      case Select:  return SDL_SCANCODE_RSHIFT;
      case R:       return SDL_SCANCODE_S;
      case L:       return SDL_SCANCODE_A;
      case Escape:  return SDL_SCANCODE_ESCAPE;
    }
  }

  bool Input::isKeyDown(Keys key) {
    SDL_Scancode scancode = convertKeyToScancode(key);

    return event_.type == SDL_KEYDOWN && keyboard_state_[scancode];
  }

  bool Input::isKeyUp(Keys key) {
    SDL_Scancode scancode = convertKeyToScancode(key);

    return event_.type == SDL_KEYUP && !keyboard_state_[scancode];
  }

  bool Input::hasQuit() {
    return event_.type == SDL_QUIT || isKeyDown(Escape);
  }
}

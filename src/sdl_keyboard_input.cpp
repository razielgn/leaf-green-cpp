#include "sdl_keyboard_input.hpp"

#include "input_key.hpp"

namespace green_leaf {
  SDLKeyboardInput::~SDLKeyboardInput() {
  }

  void SDLKeyboardInput::recordState() {
    keyboard_state_ = SDL_GetKeyboardState(NULL);
    SDL_PollEvent(&event_);
  }

  SDL_Scancode convertKeyToScancode(InputKey key) {
    switch(key) {
      case InputKey::A:       return SDL_SCANCODE_X;
      case InputKey::B:       return SDL_SCANCODE_Z;
      case InputKey::Up:      return SDL_SCANCODE_UP;
      case InputKey::Down:    return SDL_SCANCODE_DOWN;
      case InputKey::Left:    return SDL_SCANCODE_LEFT;
      case InputKey::Right:   return SDL_SCANCODE_RIGHT;
      case InputKey::Start:   return SDL_SCANCODE_RETURN;
      case InputKey::Select:  return SDL_SCANCODE_RSHIFT;
      case InputKey::R:       return SDL_SCANCODE_S;
      case InputKey::L:       return SDL_SCANCODE_A;
      case InputKey::Escape:  return SDL_SCANCODE_ESCAPE;
    }

    return SDL_SCANCODE_UNKNOWN;
  }

  bool SDLKeyboardInput::isKeyDown(InputKey key) {
    SDL_Scancode scancode = convertKeyToScancode(key);

    return event_.type == SDL_KEYDOWN && keyboard_state_[scancode];
  }

  bool SDLKeyboardInput::isKeyUp(InputKey key) {
    SDL_Scancode scancode = convertKeyToScancode(key);

    return event_.type == SDL_KEYUP && !keyboard_state_[scancode];
  }
}

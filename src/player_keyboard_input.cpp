#include "player_keyboard_input.hpp"

#include "input_key.hpp"

namespace green_leaf {
  PlayerKeyboardInput::PlayerKeyboardInput(std::unique_ptr<KeyboardInput> keyboard_input)
    : keyboard_input_(std::move(keyboard_input))
  {
  }

  void PlayerKeyboardInput::update() {
    keyboard_input_->recordState();
  }

  bool PlayerKeyboardInput::a() {
    return keyboard_input_->isKeyDown(InputKey::A);
  }

  bool PlayerKeyboardInput::b() {
    return keyboard_input_->isKeyDown(InputKey::B);
  }

  bool PlayerKeyboardInput::up() {
    return keyboard_input_->isKeyDown(InputKey::Up);
  }

  bool PlayerKeyboardInput::down() {
    return keyboard_input_->isKeyDown(InputKey::Down);
  }

  bool PlayerKeyboardInput::left() {
    return keyboard_input_->isKeyDown(InputKey::Left);
  }

  bool PlayerKeyboardInput::right() {
    return keyboard_input_->isKeyDown(InputKey::Right);
  }

  bool PlayerKeyboardInput::start() {
    return keyboard_input_->isKeyDown(InputKey::Start);
  }

  bool PlayerKeyboardInput::select() {
    return keyboard_input_->isKeyDown(InputKey::Select);
  }

  bool PlayerKeyboardInput::r() {
    return keyboard_input_->isKeyDown(InputKey::R);
  }

  bool PlayerKeyboardInput::l() {
    return keyboard_input_->isKeyDown(InputKey::L);
  }

  bool PlayerKeyboardInput::escape() {
    return keyboard_input_->isKeyDown(InputKey::Escape);
  }
}

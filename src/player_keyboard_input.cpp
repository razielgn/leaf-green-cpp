#include "player_keyboard_input.hpp"

#include "input_key.hpp"

namespace green_leaf {
  PlayerKeyboardInput::PlayerKeyboardInput(std::unique_ptr<KeyboardInput> keyboard_input)
    : keyboard_input_(std::move(keyboard_input))
  {
  }

  void PlayerKeyboardInput::update() {
    keyboard_input_->recordState();

    previous_state_ = current_state_;
    current_state_[ 0] = keyboard_input_->isKeyDown(InputKey::A);
    current_state_[ 1] = keyboard_input_->isKeyDown(InputKey::B);
    current_state_[ 2] = keyboard_input_->isKeyDown(InputKey::Up);
    current_state_[ 3] = keyboard_input_->isKeyDown(InputKey::Down);
    current_state_[ 4] = keyboard_input_->isKeyDown(InputKey::Left);
    current_state_[ 5] = keyboard_input_->isKeyDown(InputKey::Right);
    current_state_[ 6] = keyboard_input_->isKeyDown(InputKey::Start);
    current_state_[ 7] = keyboard_input_->isKeyDown(InputKey::Select);
    current_state_[ 8] = keyboard_input_->isKeyDown(InputKey::R);
    current_state_[ 9] = keyboard_input_->isKeyDown(InputKey::L);
    current_state_[10] = keyboard_input_->isKeyDown(InputKey::Escape);
  }

  bool PlayerKeyboardInput::a() {
    return current_state_[0];
  }

  bool PlayerKeyboardInput::aPressed() {
    return !previous_state_[0] && a();
  }

  bool PlayerKeyboardInput::b() {
    return current_state_[1];
  }

  bool PlayerKeyboardInput::bPressed() {
    return !previous_state_[1] && b();
  }

  bool PlayerKeyboardInput::up() {
    return current_state_[2];
  }

  bool PlayerKeyboardInput::upPressed() {
    return !previous_state_[2] && up();
  }

  bool PlayerKeyboardInput::down() {
    return current_state_[3];
  }

  bool PlayerKeyboardInput::downPressed() {
    return !previous_state_[3] && down();
  }

  bool PlayerKeyboardInput::left() {
    return current_state_[4];
  }

  bool PlayerKeyboardInput::right() {
    return current_state_[5];
  }

  bool PlayerKeyboardInput::start() {
    return current_state_[6];
  }

  bool PlayerKeyboardInput::startPressed() {
    return !previous_state_[6] && start();
  }

  bool PlayerKeyboardInput::select() {
    return current_state_[7];
  }

  bool PlayerKeyboardInput::r() {
    return current_state_[8];
  }

  bool PlayerKeyboardInput::l() {
    return current_state_[9];
  }

  bool PlayerKeyboardInput::escape() {
    return current_state_[10];
  }
}

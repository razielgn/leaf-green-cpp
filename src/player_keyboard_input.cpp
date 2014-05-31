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

  bool PlayerKeyboardInput::a() const {
    return current_state_[0];
  }

  bool PlayerKeyboardInput::aPressed() const {
    return !previous_state_[0] && a();
  }

  bool PlayerKeyboardInput::b() const {
    return current_state_[1];
  }

  bool PlayerKeyboardInput::bPressed() const {
    return !previous_state_[1] && b();
  }

  bool PlayerKeyboardInput::up() const {
    return current_state_[2];
  }

  bool PlayerKeyboardInput::upPressed() const {
    return !previous_state_[2] && up();
  }

  bool PlayerKeyboardInput::down() const {
    return current_state_[3];
  }

  bool PlayerKeyboardInput::downPressed() const {
    return !previous_state_[3] && down();
  }

  bool PlayerKeyboardInput::left() const {
    return current_state_[4];
  }

  bool PlayerKeyboardInput::right() const {
    return current_state_[5];
  }

  bool PlayerKeyboardInput::start() const {
    return current_state_[6];
  }

  bool PlayerKeyboardInput::startPressed() const {
    return !previous_state_[6] && start();
  }

  bool PlayerKeyboardInput::select() const {
    return current_state_[7];
  }

  bool PlayerKeyboardInput::r() const {
    return current_state_[8];
  }

  bool PlayerKeyboardInput::l() const {
    return current_state_[9];
  }

  bool PlayerKeyboardInput::escape() const {
    return current_state_[10];
  }
}

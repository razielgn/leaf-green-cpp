#pragma once
#ifndef GL_PLAYER_KEYBOARD_INPUT
#define GL_PLAYER_KEYBOARD_INPUT

#include "keyboard_input.hpp"
#include "player_input.hpp"

#include <array>
#include <memory>

namespace green_leaf {
  class PlayerKeyboardInput : public PlayerInput {
  public:
    PlayerKeyboardInput(std::unique_ptr<KeyboardInput> keyboard_input);

    void update() override;

    bool a() override;
    bool aPressed() override;
    bool b() override;
    bool bPressed() override;
    bool up() override;
    bool upPressed() override;
    bool down() override;
    bool downPressed() override;
    bool left() override;
    bool right() override;
    bool start() override;
    bool startPressed() override;
    bool select() override;
    bool r() override;
    bool l() override;
    bool escape() override;

  private:
    std::unique_ptr<KeyboardInput> keyboard_input_;
    std::array<bool, 11> previous_state_;
    std::array<bool, 11> current_state_;
  };
}

#endif

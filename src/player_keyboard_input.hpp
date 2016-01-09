#pragma once

#include "keyboard_input.hpp"
#include "player_input.hpp"

#include <array>
#include <memory>

namespace green_leaf {
  class PlayerKeyboardInput : public PlayerInput {
  public:
    PlayerKeyboardInput(std::unique_ptr<KeyboardInput> keyboard_input);

    void update() override;

    bool a() const override;
    bool aPressed() const override;
    bool b() const override;
    bool bPressed() const override;
    bool up() const override;
    bool upPressed() const override;
    bool down() const override;
    bool downPressed() const override;
    bool left() const override;
    bool right() const override;
    bool start() const override;
    bool startPressed() const override;
    bool select() const override;
    bool r() const override;
    bool l() const override;
    bool escape() const override;

  private:
    std::unique_ptr<KeyboardInput> keyboard_input_;
    std::array<bool, 11> previous_state_;
    std::array<bool, 11> current_state_;
  };
}

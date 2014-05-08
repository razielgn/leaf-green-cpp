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

    void update();

    bool a();
    bool aPressed();
    bool b();
    bool bPressed();
    bool up();
    bool upPressed();
    bool down();
    bool downPressed();
    bool left();
    bool right();
    bool start();
    bool startPressed();
    bool select();
    bool r();
    bool l();
    bool escape();

  private:
    std::unique_ptr<KeyboardInput> keyboard_input_;
    std::array<bool, 11> previous_state_;
    std::array<bool, 11> current_state_;
  };
}

#endif

#ifndef GL_PLAYER_KEYBOARD_INPUT
#define GL_PLAYER_KEYBOARD_INPUT

#include "keyboard_input.hpp"
#include "player_input.hpp"

#include <memory>

namespace green_leaf {
  class PlayerKeyboardInput : public PlayerInput {
  public:
    PlayerKeyboardInput(std::unique_ptr<KeyboardInput> keyboard_input);

    void update();

    bool a();
    bool b();
    bool up();
    bool down();
    bool left();
    bool right();
    bool start();
    bool select();
    bool r();
    bool l();
    bool escape();

  private:
    std::unique_ptr<KeyboardInput> keyboard_input_;
  };
}

#endif

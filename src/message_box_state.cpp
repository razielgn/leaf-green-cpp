#include "message_box_state.hpp"

#include "keyboard_input.hpp"
#include "input_key.hpp"

namespace green_leaf {
  const unsigned int CHAR_NORMAL_DELAY = 100;
  const unsigned int CHAR_FAST_DELAY = 16;

  namespace {
    bool actionButtonPressed(KeyboardInput& input) {
      return
        input.isKeyDown(InputKey::A) ||
        input.isKeyDown(InputKey::B);
    }

    unsigned int charDelayTime(KeyboardInput& input) {
      if(actionButtonPressed(input)) {
        return CHAR_FAST_DELAY;
      } else {
        return CHAR_NORMAL_DELAY;
      }
    }
  }

  MessageBoxState::MessageBoxState()
    : character_(0)
    , line_(0)
    , message_(0)
    , elapsed_(0)
  {
  }

  void MessageBoxState::nextLine() {
    character_ = 0;
    line_++;
  }

  void MessageBoxState::nextMessage() {
    character_ = 0;
    line_ = 0;
    message_++;
  }

  void MessageBoxState::update(KeyboardInput& input, GameTime game_time) {
    elapsed_ += game_time.elapsed();

    unsigned int delay = charDelayTime(input);
    if(elapsed_ >= delay) {
      character_ += elapsed_ / delay;
      elapsed_ %= delay;
    }
  }
}

#pragma once

#include "game_time.hpp"

namespace green_leaf {
  class PlayerInput;

  struct MessageBoxState {
    MessageBoxState();

    unsigned int character() const {
      return character_;
    }

    unsigned int line() const {
      return line_;
    }

    unsigned int message() const {
      return message_;
    }

    void nextLine();
    void nextMessage();

    void update(PlayerInput& input, GameTime game_time);

  private:
    unsigned int character_;
    unsigned int line_;
    unsigned int message_;
    unsigned int elapsed_;
  };
}

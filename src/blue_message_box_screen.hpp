#pragma once

#include "message_box_screen.hpp"

namespace green_leaf {
  class BlueMessageBoxScreen : public MessageBoxScreen {
  public:
    BlueMessageBoxScreen(ScreenManager& screen_manager, const std::vector<message> messages)
      : MessageBoxScreen(screen_manager, messages)
    {
    }

  protected:
    const Vector2 boxSkin() const override {
      return Vector2(0, 0);
    }
  };
}

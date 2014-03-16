#include "screen.hpp"

#include "screen_manager.hpp"

namespace green_leaf {
  Screen::Screen(ScreenManager& screen_manager)
    : screen_manager_(screen_manager)
  {
  }

  void Screen::popScreen() {
    screen_manager_.pop();
  }

  void Screen::pushScreen(std::unique_ptr<Screen> screen) {
    screen_manager_.push(std::move(screen));
  }
}

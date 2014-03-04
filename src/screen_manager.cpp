#include "screen_manager.hpp"

#include "screen.hpp"

namespace green_leaf {
  unsigned long ScreenManager::count() const {
    return screens_.size();
  }

  void ScreenManager::push(Screen* screen) {
    screens_.push_back(screen);
  }

  void ScreenManager::pop() {
    screens_.pop_back();
  }

  void ScreenManager::update(Input* input, const GameTime* game_time) {
    if(count() == 0u) {
      return;
    }

    screens_.back()->update(input, game_time);
  }

  void ScreenManager::draw(const Graphics* graphics) {
    for(auto screen : screens_) {
      screen->draw(graphics);
    }
  }
}

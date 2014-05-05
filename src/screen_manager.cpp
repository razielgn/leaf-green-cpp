#include "screen_manager.hpp"

#include "screen.hpp"

namespace green_leaf {
  ScreenManager::ScreenManager(const Content& content)
    : content_(content)
  {
  }

  unsigned long ScreenManager::count() const {
    return screens_.size();
  }

  void ScreenManager::push(std::unique_ptr<Screen> screen) {
    screen->loadContent(content_);
    screens_.push_back(std::move(screen));
  }

  void ScreenManager::pop() {
    screens_.pop_back();
  }

  void ScreenManager::update(PlayerInput& input, const GameTime game_time) const {
    if(count() == 0u) {
      return;
    }

    screens_.back()->update(input, game_time);
  }

  void ScreenManager::draw(const Graphics& graphics) const {
    for(auto &screen : screens_) {
      screen->draw(graphics);
    }
  }
}

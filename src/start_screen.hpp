#ifndef GL_START_SCREEN_HPP
#define GL_START_SCREEN_HPP

#include "hint_box.hpp"
#include "screen.hpp"
#include "vertical_menu_box.hpp"

namespace green_leaf {
  class StartScreen : public Screen {
  public:
    StartScreen(ScreenManager& screen_manager);

    void loadContent(const Content& content);
    void update(PlayerInput& input, const GameTime game_time);
    void draw(const Graphics& graphics) const;

  private:
    VerticalMenuBox right_box_;
    HintBox hint_box_;
  };
}

#endif

#pragma once

#include "hint_box.hpp"
#include "screen.hpp"
#include "vertical_menu_box.hpp"

namespace green_leaf {
  class StartScreen : public Screen {
  public:
    StartScreen(ScreenManager& screen_manager);

    void loadContent(const Content& content) override;
    void update(PlayerInput& input, const GameTime game_time) override;
    void draw(const Graphics& graphics) const override;

  private:
    VerticalMenuBox right_box_;
    HintBox hint_box_;
  };
}

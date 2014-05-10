#include "start_screen.hpp"

#include "player_input.hpp"
#include "rectangle.hpp"
#include "unused.hpp"

namespace green_leaf {
  namespace {
    const Rectangle left_box_rect(169, 1, 70, 0);
    const std::vector<const std::string> entries {
      { "BAG", "FRED", "SAVE", "OPTION", "EXIT" }
    };

    bool hasClosedScreen(PlayerInput& input, const VerticalMenuBox& box) {
      if(input.startPressed() || input.bPressed()) {
        return true;
      }

      return box.selectedEntry() == entries.size() - 1 && input.aPressed();
    }
  }

  StartScreen::StartScreen(ScreenManager& screen_manager)
    : Screen(screen_manager)
    , right_box_(entries, 0, left_box_rect.width(), left_box_rect.origin())
  {
  }

  void StartScreen::loadContent(const Content& content) {
    right_box_.loadContent(content);
  }

  void StartScreen::update(PlayerInput& input, const GameTime game_time) {
    UNUSED(game_time);

    right_box_.update(input);

    if(hasClosedScreen(input, right_box_)) {
      popScreen();
    }
  }

  void StartScreen::draw(const Graphics& graphics) const {
    right_box_.draw(graphics);
  }
}

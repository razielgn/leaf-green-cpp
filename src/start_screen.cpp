#include "start_screen.hpp"

#include "custom_types.hpp"
#include "player_input.hpp"
#include "rectangle.hpp"
#include "unused.hpp"

namespace green_leaf {
  namespace {
    const Rectangle left_box_rect(169, 1, 70, 0);
    const std::vector<const std::string> entries {
      { "BAG", "FRED", "SAVE", "OPTION", "EXIT" }
    };
    const std::vector<message> hint_messages {
      { "Equipped with pockets for storing items", "you bought, received, or found." },
      { "Check your money and other game data.", "" },
      { "Save your game with a complete record", "of your progress to take a break." },
      { "Adjust various game settings such as text", "speed, game rules, etc." },
      { "Close this MENU window.", "" },
    };

    bool hasClosedScreen(PlayerInput& input, const VerticalMenuBox& box) {
      if(input.startPressed() || input.bPressed()) {
        return true;
      }

      bool lastEntry = box.selectedEntry() == entries.size() - 1;
      return input.aPressed() && lastEntry;
    }
  }

  StartScreen::StartScreen(ScreenManager& screen_manager)
    : Screen(screen_manager)
    , right_box_(entries, 0, left_box_rect.width(), left_box_rect.origin())
    , hint_box_(hint_messages)
  {
  }

  void StartScreen::loadContent(const Content& content) {
    right_box_.loadContent(content);
    hint_box_.loadContent(content);
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
    hint_box_.draw(graphics, right_box_.selectedEntry());
  }
}

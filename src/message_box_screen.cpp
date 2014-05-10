#include "message_box_screen.hpp"

#include "content.hpp"
#include "graphics.hpp"
#include "player_input.hpp"
#include "utils/string.hpp"

namespace green_leaf {
  const Rectangle RED_ARROW_SRC(48, 0, 10, 6);
  const Vector2 BOX_OFFSET(0, 16 * 7);
  const Vector2 FIRST_LINE_OFFSET(16, BOX_OFFSET.y() + 9);
  const Vector2 SECOND_LINE_OFFSET = FIRST_LINE_OFFSET + Vector2(0, 15);
  const unsigned int RED_ARROW_INSET = 2;

  namespace {
    const Vector2 lineOffset(unsigned int index) {
      switch(index) {
        case 0: return FIRST_LINE_OFFSET;
        case 1: return SECOND_LINE_OFFSET;
      }

      return Vector2(0, 0);
    }
  }

  MessageBoxScreen::MessageBoxScreen(ScreenManager& screen_manager, const std::vector<message> messages)
    : Screen(screen_manager)
    , messages_(messages)
  {
  }

  void MessageBoxScreen::loadContent(const Content& content) {
    menus_ = content.loadTexture("menus.gif");
    font_ = content.loadBitmapFont("font1.gif");
  }

  const message MessageBoxScreen::currentMessage() const {
    return messages_.at(state_.message());
  }

  const std::string MessageBoxScreen::lineAt(size_t index) const {
    if(index == 0) {
      return std::get<0>(currentMessage());
    } else {
      return std::get<1>(currentMessage());
    }
  }

  const std::string MessageBoxScreen::currentLine() const {
    return lineAt(state_.line());
  }

  bool MessageBoxScreen::endOfLine() const {
    return state_.character() >= utils::utf8Length(currentLine());
  }

  bool MessageBoxScreen::endOfMessage() const {
    if(endOfLine()) {
      if(state_.line() == 0 && lineAt(1).empty()) {
        return true;
      }

      if(state_.line() == 1) {
        return true;
      }
    }

    return false;
  }

  bool MessageBoxScreen::lastMessage() const {
    return state_.message() == messages_.size() - 1;
  }

  void MessageBoxScreen::update(PlayerInput& input, const GameTime game_time) {
    // 1. Run line animation (if A or B is pressed, go faster)
    // 2. Wait for input (red triangle animating)
    // 3. Go to next line and start from 1

    if(endOfMessage()) {
      triangle_state_.update(game_time);

      if(input.aPressed() || input.bPressed()) {
        if(lastMessage()) {
          popScreen();
        } else {
          state_.nextMessage();
        }
      }
    } else {
      if(endOfLine()) {
        state_.nextLine();
      } else {
        state_.update(input, game_time);
      }
    }
  }

  void MessageBoxScreen::drawBackground(const Graphics& graphics) const {
    // Left border.
    for(int i = 7, j = 0; i < 10; i++, j++) {
      graphics.drawTexture(*menus_, Vector2(0, i) * 16, Rectangle(0, j, 1, 1) * 16);
    }

    // Middle section 14 times.
    for(int m = 1; m < 14; m++) {
      for(int i = 7, j = 0; i < 10; i++, j++) {
        graphics.drawTexture(*menus_, Vector2(m, i) * 16, Rectangle(1, j, 1, 1) * 16);
      }
    }

    // Right border.
    for(int i = 7, j = 0; i < 10; i++, j++) {
      graphics.drawTexture(*menus_, Vector2(14, i) * 16, Rectangle(2, j, 1, 1) * 16);
    }
  }

  unsigned int MessageBoxScreen::drawLine(const Graphics& graphics, unsigned int index, const std::string msg) const {
    return font_->drawString(graphics, lineOffset(index), msg);
  }

  unsigned int MessageBoxScreen::drawLine(const Graphics& graphics, unsigned int index, const std::string msg, size_t chars) const {
    return font_->drawString(graphics, lineOffset(index), msg, chars);
  }

  void MessageBoxScreen::drawArrow(const Graphics& graphics, Vector2 offset) const {
    graphics.drawTexture(*menus_, offset, RED_ARROW_SRC);
  }

  void MessageBoxScreen::draw(const Graphics& graphics) const {
    drawBackground(graphics);

    if(state_.line() == 1) {
      drawLine(graphics, 0, lineAt(0));
    }

    unsigned int full_width = drawLine(graphics, state_.line(), currentLine(), state_.character());

    if(endOfMessage()) {
      if(lastMessage()) {
        return;
      }

      Vector2 line_end(full_width, lineOffset(state_.line()).y());
      Vector2 arrow_offset = line_end + Vector2(0, RED_ARROW_INSET + triangle_state_.offset());
      drawArrow(graphics, arrow_offset);
    }
  }
}

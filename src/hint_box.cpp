#include "hint_box.hpp"

#include "content.hpp"
#include "graphics.hpp"

namespace green_leaf {
  namespace {
    const Rectangle surface(0, 120, 240, 40);
    const Rectangle source(64, 0, 1, 40);
    const Vector2 first_line(2, 125);
    const Vector2 second_line = first_line + Vector2(0, 15);
  }

  HintBox::HintBox(const std::vector<message> messages)
    : messages_(messages)
  {
  }

  void HintBox::loadContent(const Content& content) {
    menus_ = content.loadTexture("menus.gif");
    font_ = content.loadBitmapFont("font2.gif");
  }

  void HintBox::draw(const Graphics& graphics, size_t selected_message) const {
    message hint_message = messages_[selected_message];

    // Background
    graphics.drawTexture(*menus_, surface, source);

    // Lines
    font_->drawString(graphics, first_line, hint_message.first);
    font_->drawString(graphics, second_line, hint_message.second);
  }
}

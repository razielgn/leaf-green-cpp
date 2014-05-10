#include "vertical_menu_box.hpp"

#include "content.hpp"
#include "graphics.hpp"
#include "player_input.hpp"

namespace green_leaf {
  namespace {
    const unsigned text_line_height = 15;
    const Vector2 line_offset(15, 7);

    const Vector2 arrow_offset(8, 9);

    const Vector2 corner_tile(6, 6);
    const Vector2 border_middle_tile(1, 6);
    const Vector2 middle_tile(6, 1);

    const Vector2 left_border_offset(6, 0);

    const Rectangle top_left_corner(0, 48, corner_tile);
    const Rectangle top_middle_section(6, 48, border_middle_tile);
    const Rectangle top_right_corner(7, 48, corner_tile);

    const Rectangle bottom_left_corner(0, 55, corner_tile);
    const Rectangle bottom_middle_section(6, 55, border_middle_tile);
    const Rectangle bottom_right_corner(7, 55, corner_tile);

    const Rectangle middle_left_section(0, 54, middle_tile);
    const Rectangle middle_white_section(6, 54, 1, 1);
    const Rectangle middle_right_section(7, 54, middle_tile);

    const Rectangle arrow(48, 16, 6, 10);
  }

  VerticalMenuBox::VerticalMenuBox(const std::vector<const std::string> entries, size_t selected_entry, unsigned int width, const Vector2 origin)
    : entries_(entries)
    , selected_entry_(selected_entry)
    , width_(width - corner_tile.x() * 2)
    , middle_row_height_(entries.size() * text_line_height - 1)
    , origin_(origin)
    , middle_row_origin_(origin_ + Vector2(0, 6))
    , bottom_row_origin_(middle_row_origin_ + Vector2(0, middle_row_height_))
    , right_border_offset_(width_ + 6, 0)
  {
  }

  void VerticalMenuBox::loadContent(const Content& content) {
    menus_ = content.loadTexture("menus.gif");
    font_ = content.loadBitmapFont("font1.gif");
  }

  void VerticalMenuBox::update(PlayerInput& input) {
    if(input.downPressed()) {
      selected_entry_ = (selected_entry_ + 1) % entries_.size();
    }

    if(input.upPressed()) {
      if(selected_entry_ == 0) {
        selected_entry_ = entries_.size() - 1;
      } else {
        selected_entry_ -= 1;
      }
    }
  }

  void VerticalMenuBox::draw(const Graphics& graphics) const {
    // Top border
    graphics.drawTexture(*menus_, origin_, top_left_corner);
    graphics.drawTexture(*menus_, Rectangle(origin_ + left_border_offset, width_, 6), top_middle_section);
    graphics.drawTexture(*menus_, origin_ + right_border_offset_, top_right_corner);

    // Middle section
    graphics.drawTexture(*menus_, Rectangle(middle_row_origin_, 6, middle_row_height_), middle_left_section);
    graphics.drawTexture(*menus_, Rectangle(middle_row_origin_ + left_border_offset, width_, middle_row_height_), middle_white_section);
    graphics.drawTexture(*menus_, Rectangle(middle_row_origin_ + right_border_offset_, 6, middle_row_height_), middle_right_section);

    // Bottom border
    graphics.drawTexture(*menus_, bottom_row_origin_, bottom_left_corner);
    graphics.drawTexture(*menus_, Rectangle(bottom_row_origin_ + left_border_offset, width_, 6), bottom_middle_section);
    graphics.drawTexture(*menus_, bottom_row_origin_ + right_border_offset_, bottom_right_corner);

    // Menu entries
    for(size_t i = 0; i < entries_.size(); i++) {
      const Vector2 current_line_offset(0, i * text_line_height);

      font_->drawString(graphics, origin_ + line_offset + current_line_offset, entries_[i]);

      if(selected_entry_ == i) {
        graphics.drawTexture(*menus_, origin_ + arrow_offset + current_line_offset, arrow);
      }
    }
  }
}

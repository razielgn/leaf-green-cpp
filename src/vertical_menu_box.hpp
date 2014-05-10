#ifndef GL_VERTICAL_MENU_BOX_HPP
#define GL_VERTICAL_MENU_BOX_HPP

#include "bitmap_font.hpp"
#include "texture.hpp"

#include <string>
#include <vector>

namespace green_leaf {
  class Content;
  class Graphics;
  class PlayerInput;

  class VerticalMenuBox {
  public:
    VerticalMenuBox(const std::vector<const std::string> entries, size_t selected_entry, unsigned int width, const Vector2 origin);

    void loadContent(const Content& content);
    void update(PlayerInput& input);
    void draw(const Graphics& graphics) const;

    size_t selectedEntry() const {
      return selected_entry_;
    }

  private:
    std::unique_ptr<const Texture> menus_;
    std::unique_ptr<const BitmapFont> font_;

    const std::vector<const std::string> entries_;
    size_t selected_entry_;

    const unsigned int width_;
    const unsigned int middle_row_height_;
    const Vector2 origin_;
    const Vector2 middle_row_origin_;
    const Vector2 bottom_row_origin_;
    const Vector2 right_border_offset_;
  };
}

#endif

#pragma once
#ifndef GL_HINT_BOX_HPP
#define GL_HINT_BOX_HPP

#include "bitmap_font.hpp"
#include "custom_types.hpp"
#include "texture.hpp"

#include <vector>

namespace green_leaf {
  class Content;
  class Graphics;

  class HintBox {
  public:
    HintBox(const std::vector<message> messages);

    void loadContent(const Content& content);
    void draw(const Graphics& graphics, size_t selected_message) const;

  private:
    std::unique_ptr<const Texture> menus_;
    std::unique_ptr<const BitmapFont> font_;

    const std::vector<message> messages_;
  };
}

#endif

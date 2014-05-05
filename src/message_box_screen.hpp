#ifndef GL_MESSAGE_BOX_SCREEN_HPP
#define GL_MESSAGE_BOX_SCREEN_HPP

#include "bitmap_font.hpp"
#include "custom_types.hpp"
#include "menu_triangle_state.hpp"
#include "message_box_state.hpp"
#include "screen.hpp"
#include "texture.hpp"

#include <memory>
#include <vector>

namespace green_leaf {
  class Content;
  class Graphics;
  class KeyboardInput;

  class MessageBoxScreen : public Screen {
  public:
    MessageBoxScreen(ScreenManager& screen_manager, const std::vector<message> messages);

    void loadContent(const Content& content);
    void update(KeyboardInput& input, const GameTime game_time);
    void draw(const Graphics& graphics) const;

  private:
    std::unique_ptr<const Texture> menus_;
    std::unique_ptr<const BitmapFont> font_;

    const std::vector<message> messages_;

    MenuTriangleState triangle_state_;
    MessageBoxState state_;

    void drawBackground(const Graphics& graphics) const;
    void drawArrow(const Graphics& graphics, Vector2 offset) const;
    unsigned int drawLine(const Graphics& graphics, unsigned int index, const std::string msg) const;
    unsigned int drawLine(const Graphics& graphics, unsigned int index, const std::string msg, size_t chars) const;

    const message currentMessage() const;
    const std::string currentLine() const;
    const std::string lineAt(size_t index) const;
    bool endOfLine() const;
    bool endOfMessage() const;
    bool lastMessage() const;
  };
}

#endif

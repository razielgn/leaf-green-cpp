#ifndef GL_SCREEN_HPP
#define GL_SCREEN_HPP

#include "game_time.hpp"

namespace green_leaf {
  class Content;
  class Graphics;
  class Input;

  class Screen {
  public:
    virtual ~Screen() { }

    virtual void loadContent(const Content& content) = 0;
    virtual void update(Input& input, const GameTime game_time) = 0;
    virtual void draw(const Graphics& graphics) const = 0;
  };
}

#endif

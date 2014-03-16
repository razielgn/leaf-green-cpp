#ifndef GL_SCREEN_HPP
#define GL_SCREEN_HPP

#include "game_time.hpp"

#include <memory>

namespace green_leaf {
  class Content;
  class Graphics;
  class Input;
  class ScreenManager;

  class Screen {
  public:
    Screen(ScreenManager& screen_manager);
    virtual ~Screen() { }

    virtual void loadContent(const Content& content) = 0;
    virtual void update(Input& input, const GameTime game_time) = 0;
    virtual void draw(const Graphics& graphics) const = 0;

  protected:
    ScreenManager& screenManager() const {
      return screen_manager_;
    }

    void popScreen();
    void pushScreen(std::unique_ptr<Screen> screen);

  private:
    ScreenManager& screen_manager_;
  };
}

#endif

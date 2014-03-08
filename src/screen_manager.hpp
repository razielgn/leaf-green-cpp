#ifndef GL_SCREEN_MANAGER_HPP
#define GL_SCREEN_MANAGER_HPP

#include "game_time.hpp"

#include <memory>
#include <vector>

namespace green_leaf {
  class GameTime;
  class Graphics;
  class Input;
  class Screen;

  class ScreenManager {
  public:
    unsigned long count() const;
    void push(std::unique_ptr<Screen> screen);
    void pop();

    void update(Input& input, const GameTime game_time);
    void draw(const Graphics& graphics);

  private:
    std::vector<std::unique_ptr<Screen>> screens_;
  };
}

#endif

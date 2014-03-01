#ifndef GL_SCREEN_MANAGER_HPP
#define GL_SCREEN_MANAGER_HPP

#include <vector>

namespace green_leaf {
  class GameTime;
  class Graphics;
  class Input;
  class Screen;

  class ScreenManager {
  public:
    unsigned int count() const;
    void push(Screen* screen);
    void pop();

    void update(Input* input, const GameTime* game_time);
    void draw(const Graphics* graphics);

  private:
    std::vector<Screen*> screens_;
  };
}

#endif

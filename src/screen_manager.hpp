#pragma once
#ifndef GL_SCREEN_MANAGER_HPP
#define GL_SCREEN_MANAGER_HPP

#include "screen.hpp"

#include <memory>
#include <vector>

namespace green_leaf {
  class Content;
  class GameTime;
  class Graphics;
  class PlayerInput;

  class ScreenManager {
  public:
    ScreenManager(const Content& content);

    unsigned long count() const;
    void push(std::unique_ptr<Screen> screen);
    void pop();

    void update(PlayerInput& input, const GameTime game_time) const;
    void draw(const Graphics& graphics) const;

  private:
    std::vector<std::unique_ptr<Screen>> screens_;

    const Content& content_;
  };
}

#endif

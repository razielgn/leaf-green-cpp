#ifndef GL_GAME_CPP
#define GL_GAME_CPP

#include <SDL_image.h>

#include "graphics.hpp"

namespace green_leaf {
  class Game {
  public:
    Game();
    ~Game();

    void loadContent();
    void unloadContent();
    void run();
    void update();
    void stop();

  private:
    Graphics* graphics_;
    Texture* hero_texture_;
    bool running_;
  };
}

#endif

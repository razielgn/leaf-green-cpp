#ifndef GL_GAME_CPP
#define GL_GAME_CPP

#include <vector>

namespace green_leaf {
  class Content;
  class Graphics;
  class Input;
  class Screen;

  class Game {
  public:
    Game();
    ~Game();

    void loadContent();
    void run();
    void update();
    void draw() const;
    void stop();

  private:
    Graphics* graphics_;
    Input* input_;
    Content* content_;
    std::vector<Screen*> screens_;

    unsigned int total_time_;
    bool running_;
  };
}

#endif

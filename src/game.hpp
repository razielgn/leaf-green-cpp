#ifndef GL_GAME_CPP
#define GL_GAME_CPP

namespace green_leaf {
  class Graphics;
  class Input;
  class Player;

  class Game {
  public:
    Game();
    ~Game();

    void loadContent();
    void unloadContent();
    void run();
    void update();
    void draw();
    void stop();

  private:
    Graphics* graphics_;
    Input* input_;
    Player* player_;

    bool running_;
  };
}

#endif

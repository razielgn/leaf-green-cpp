#ifndef GL_GAME_CPP
#define GL_GAME_CPP

namespace green_leaf {
  class Content;
  class Graphics;
  class Input;
  class MapScreen;
  class Screen;
  class ScreenManager;

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
    ScreenManager* screen_manager_;
    MapScreen* hero_home_2f_;

    unsigned int total_time_;
    bool running_;
  };
}

#endif

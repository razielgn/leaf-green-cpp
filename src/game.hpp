#ifndef GL_GAME_CPP
#define GL_GAME_CPP

namespace green_leaf {
  class Content;
  class Graphics;
  class Input;
  class Player;
  class PlayerMovement;
  class Map;

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
    Map* map_;
    PlayerMovement* player_movement_;
    Content* content_;

    unsigned int total_time_;
    bool running_;
  };
}

#endif

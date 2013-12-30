#ifndef GL_PLAYER_HPP
#define GL_PLAYER_HPP

namespace green_leaf {
  class GameTime;
  class Graphics;
  class Input;
  class Texture;

  class Player {
  public:
    Player();
    void loadContent(Graphics* graphics);
    void unloadContent();

    void update(Input* input, GameTime* game_time);
    void draw(Graphics* graphics);

  private:
    Texture* texture_;

    const int movement_time_ = 250;
    int elapsed_;
    int frame_number_;
    int direction_;
    bool walking_;
    int a_;
  };
}

#endif

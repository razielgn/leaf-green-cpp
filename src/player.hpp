#ifndef GL_PLAYER_HPP
#define GL_PLAYER_HPP

namespace green_leaf {
  class GameTime;
  class Graphics;
  class Input;
  class Texture;

  class Player {
  public:
    void loadContent(Graphics* graphics);
    void unloadContent();

    void update(Input* input, GameTime* game_time);
    void draw(Graphics* graphics);

  private:
    Texture* texture_;

    bool walking_ = false;
    unsigned int direction_ = 0;
    int frame_number_ = 0;
  };
}

#endif

#ifndef GL_MAP_HPP
#define GL_MAP_HPP

namespace green_leaf {
  class GameTime;
  class Graphics;
  class Input;
  class Texture;

  class Map {
  public:
    void loadContent(Graphics* graphics);
    void unloadContent();
    void update(Input* input, GameTime* game_time);
    void draw(Graphics* graphics);

  private:
    Texture* background_;
  };
}

#endif

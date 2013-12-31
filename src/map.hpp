#ifndef GL_MAP_HPP
#define GL_MAP_HPP

#include "point.hpp"

namespace green_leaf {
  class GameTime;
  class Graphics;
  class Input;
  class PlayerMovement;
  class Texture;

  class Map {
  public:
    Map(Point center);
    void loadContent(Graphics* graphics);
    void unloadContent();
    void update(Input* input, GameTime* game_time, PlayerMovement* player_movement);
    void draw(Graphics* graphics);
    Point drawOffset(Point center, Point map_dimension) const;

  private:
    Texture* background_;
    Point center_;
    Point dimension_;

    static const int tile_size_ = 16;

    Point destination_;
    Point offset_;
  };
}

#endif

#ifndef GL_MAP_HPP
#define GL_MAP_HPP

#include "vector2.hpp"

namespace green_leaf {
  class Content;
  class GameTime;
  class Graphics;
  class Input;
  class PlayerMovement;
  class Texture;

  class Map {
  public:
    Map(Vector2 center);
    void loadContent(const Content* content);
    void unloadContent();
    void update(const PlayerMovement* player_movement);
    void draw(Graphics* graphics);
    Vector2 drawOffset(Vector2 center, Vector2 map_dimension) const;

  private:
    Texture* background_;
    Vector2 center_;
    Vector2 dimension_;

    static const int tile_size_ = 16;

    Vector2 destination_;
    Vector2 offset_;
  };
}

#endif

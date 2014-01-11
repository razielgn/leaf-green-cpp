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
  class TileLayer;
  class TileSet;

  class Map {
  public:
    Map(Vector2 center);
    void loadContent(const Content* content);
    void unloadContent();
    void update(const PlayerMovement* player_movement);
    void drawBackground(const Graphics* graphics) const;
    void drawForeground(const Graphics* graphics) const;
    Vector2 drawOffset(Vector2 center, Vector2 map_dimension) const;

  private:
    Texture* texture_background_;
    Texture* texture_objects_;
    TileSet* tile_set_background_;
    TileSet* tile_set_objects_;
    TileLayer* tile_layer_foreground_;
    TileLayer* tile_layer_objects_;
    TileLayer* tile_layer_floor_;
    TileLayer* tile_layer_background_;

    Vector2 center_;
    Vector2 dimension_;

    Vector2 destination_;
    Vector2 offset_;
  };
}

#endif

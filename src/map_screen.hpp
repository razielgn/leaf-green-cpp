#ifndef GL_MAP_SCREEN_HPP
#define GL_MAP_SCREEN_HPP

#include "screen.hpp"
#include "vector2.hpp"

namespace green_leaf {
  class Map;
  class MapSource;
  class Player;
  class PlayerMovement;

  class MapScreen : public Screen {
  public:
    MapScreen(const MapSource* source, Vector2 start_pos, Vector2 screen_size);
    ~MapScreen();

    void loadContent(const Content* content);
    void update(Input* input, const GameTime* game_time);
    void draw(const Graphics* graphics) const;

  private:
    Map* map_;
    Player* player_;
    PlayerMovement* player_movement_;
  };
}

#endif

#include "map.hpp"

#include "collisions_layer.hpp"
#include "content.hpp"
#include "graphics.hpp"
#include "map_source.hpp"
#include "movement.hpp"
#include "player_movement.hpp"
#include "rectangle.hpp"
#include "tile_layer.hpp"
#include "vector2.hpp"
#include "vector2f.hpp"

namespace green_leaf {
  Map::Map(const MapSource& map_source, const Vector2 screen_size)
    : map_offset_(MapOffset(map_source.tileSize(), screen_size))
    , screen_offset_(Vector2(0, 0))
  {
  }

  void Map::reset(const Vector2 player_position) {
    screen_offset_ = map_offset_.centerOffset(player_position);
  }

  void Map::update(const PlayerMovement& player_movement, const Vector2 player_position, const Vector2 destination) {
    if(!player_movement.moving() || player_movement.clashing()) {
      return;
    }

    reset(player_position);

    Vector2 destination_offset = map_offset_.centerOffset(destination);
    Vector2 movement_offset = destination_offset - screen_offset_;
    Vector2f movement_delta = Vector2f(movement_offset) * player_movement.progress();

    screen_offset_ = screen_offset_ + movement_delta.toVector2();
  }

  void Map::drawBackground(const Graphics& graphics, const MapSource& map_source) const {
    map_source.backgroundLayer().draw(graphics, screen_offset_);
    map_source.floorLayer().draw(graphics, screen_offset_);
    map_source.decorationsLayer().draw(graphics, screen_offset_);
  }

  void Map::drawForeground(const Graphics& graphics, const MapSource& map_source) const {
    map_source.foregroundLayer().draw(graphics, screen_offset_);
  }
}

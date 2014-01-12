#include "content.hpp"
#include "graphics.hpp"
#include "map.hpp"
#include "map_source.hpp"
#include "movement.hpp"
#include "player_movement.hpp"
#include "tile_layer.hpp"
#include "vector2.hpp"
#include "rectangle.hpp"

namespace green_leaf {
  MapOffset::MapOffset(Vector2 tile_size, Vector2 screen_size)
    : tile_size_(tile_size)
    , screen_size_(screen_size)
  {
  }

  Vector2 MapOffset::centerOffset(Vector2 center) const {
    return (screen_size_ / 2 - tile_size_ / 2 + Vector2(0, 2)) -
      center * tile_size_;
  }

  Map::Map(const MapSource* map_source, Vector2 player_position, Vector2 screen_size)
    : map_source_(map_source)
    , map_offset_(MapOffset(map_source_->tile_size(), screen_size))
    , player_position_(player_position)
    , destination_(player_position_)
    , screen_offset_(Vector2(0, 0))
  {
  }

  void Map::update(const PlayerMovement* player_movement) {
    if(player_movement->moving()) {
      switch(player_movement->movement()) {
        case Movement::Right:
          destination_ = player_position_ + Vector2(1, 0); break;
        case Movement::Left:
          destination_ = player_position_ - Vector2(1, 0); break;
        case Movement::Up:
          destination_ = player_position_ - Vector2(0, 1); break;
        case Movement::Down:
          destination_ = player_position_ + Vector2(0, 1); break;
        default: break;
      }
    }

    screen_offset_ = map_offset_.centerOffset(player_position_);

    if(player_movement->moving()) {
      Vector2 destination = map_offset_.centerOffset(destination_);
      screen_offset_ = screen_offset_ + (destination - screen_offset_) * player_movement->progress();

      if(player_movement->finished()) {
        player_position_ = destination_;
      }
    }
  }

  void Map::drawBackground(const Graphics* graphics) const {
    map_source_->backgroundLayer()->draw(graphics, screen_offset_);
    map_source_->floorLayer()->draw(graphics, screen_offset_);
    map_source_->decorationsLayer()->draw(graphics, screen_offset_);
  }

  void Map::drawForeground(const Graphics* graphics) const {
    map_source_->foregroundLayer()->draw(graphics, screen_offset_);
  }
}

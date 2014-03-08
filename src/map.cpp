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
  Map::Map(const MapSource& map_source, Vector2 player_position, Vector2 screen_size)
    : map_offset_(MapOffset(map_source.tileSize(), screen_size))
    , player_position_(player_position)
    , destination_(player_position_)
    , screen_offset_(Vector2(0, 0))
    , camera_stopped_(true)
  {
  }

  void Map::update(PlayerMovement& player_movement, const CollisionsLayer& collisions_layer) {
    screen_offset_ = map_offset_.centerOffset(player_position_);

    if(player_movement.moving()) {
      if(camera_stopped_) {
        Vector2 desired_destination_(0, 0);

        switch(player_movement.movement()) {
          case Movement::Right:
            desired_destination_ = player_position_ + Vector2(1, 0); break;
          case Movement::Left:
            desired_destination_ = player_position_ - Vector2(1, 0); break;
          case Movement::Up:
            desired_destination_ = player_position_ - Vector2(0, 1); break;
          case Movement::Down:
            desired_destination_ = player_position_ + Vector2(0, 1); break;
          case Movement::Still:
          default: break;
        }

        if(collisions_layer.canMove(player_position_, desired_destination_)) {
          destination_ = desired_destination_;
          camera_stopped_ = false;
        } else {
          player_movement.clashing(true);
        }
      }

      Vector2 destination = map_offset_.centerOffset(destination_);
      Vector2f something = Vector2f(destination - screen_offset_) * player_movement.progress();
      screen_offset_ = screen_offset_ + something.toVector2();
    }

    if(player_movement.finished()) {
      player_position_ = destination_;
      camera_stopped_ = true;
    }
  }

  void Map::drawBackground(const Graphics& graphics, const MapSource& map_source) const {
    map_source.backgroundLayer()->draw(graphics, screen_offset_);
    map_source.floorLayer()->draw(graphics, screen_offset_);
    map_source.decorationsLayer()->draw(graphics, screen_offset_);
  }

  void Map::drawForeground(const Graphics& graphics, const MapSource& map_source) const {
    map_source.foregroundLayer()->draw(graphics, screen_offset_);
  }
}

#include "map_screen.hpp"

#include "content.hpp"
#include "game_time.hpp"
#include "map.hpp"
#include "map_collision.hpp"
#include "map_source.hpp"
#include "movement.hpp"
#include "player.hpp"
#include "player_movement.hpp"

namespace green_leaf {
  namespace {
    Vector2 movementDestination(const Vector2 start, const Movement movement) {
      switch(movement) {
        case Movement::Right: return start + Vector2(1, 0); break;
        case Movement::Left:  return start - Vector2(1, 0); break;
        case Movement::Up:    return start - Vector2(0, 1); break;
        case Movement::Down:  return start + Vector2(0, 1); break;
        default:              return start; break;
      }
    }
  }

  MapScreen::MapScreen(ScreenManager& screen_manager, std::string map_name, Vector2 start_pos, Vector2 screen_size)
    : Screen(screen_manager)
    , map_name_(map_name)
    , screen_size_(screen_size)
    , player_position_(start_pos)
  {
  }

  void MapScreen::loadContent(const Content& content) {
    map_source_ = content.loadMap(map_name_);
    player_.loadContent(content);

    map_ = std::make_unique<Map>(*map_source_, screen_size_);
    map_->reset(player_position_);
  }

  void MapScreen::update(Input& input, const GameTime game_time) {
    player_movement_.update(input, game_time);

    Vector2 destination = movementDestination(player_position_, player_movement_.movement());

    MapCollision map_collision(map_source_->collisionsLayer());
    map_collision.update(player_movement_, player_position_, destination);

    player_.update(player_movement_);
    map_->update(player_movement_, player_position_, destination);

    if(player_movement_.finished() && !player_movement_.clashing()) {
      player_position_ = destination;
    }
  }

  void MapScreen::draw(const Graphics& graphics) const {
    map_->drawBackground(graphics, *map_source_);
    player_.draw(graphics);
    map_->drawForeground(graphics, *map_source_);
  }
}

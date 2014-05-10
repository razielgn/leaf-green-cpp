#include "map_screen.hpp"

#include "content.hpp"
#include "game_time.hpp"
#include "map.hpp"
#include "map_collision.hpp"
#include "map_source.hpp"
#include "movement.hpp"
#include "object_interaction.hpp"
#include "player.hpp"
#include "player_input.hpp"
#include "player_movement.hpp"
#include "start_screen.hpp"

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

  MapScreen::MapScreen(ScreenManager& screen_manager, const std::string map_name, Vector2 start_pos, Movement facing_direction, const Vector2 screen_size)
    : Screen(screen_manager)
    , map_name_(map_name)
    , screen_size_(screen_size)
    , maybe_next_screen_(nullptr)
    , player_(facing_direction)
    , player_movement_(facing_direction)
    , player_position_(start_pos)
  {
  }

  void MapScreen::loadContent(const Content& content) {
    map_source_ = content.loadMap(map_name_);
    player_.loadContent(content);

    map_ = std::make_unique<Map>(map_source_->tileSize(), screen_size_);
    map_->setup(player_position_);
  }

  void MapScreen::updateInteractions(PlayerInput& input) {
    const Vector2 facing = movementDestination(player_position_, player_movement_.direction());

    const ObjectInteraction object_interaction(map_source_->objects());
    maybe_next_screen_ = object_interaction.update(screenManager(), facing, input);
  }

  void MapScreen::update(PlayerInput& input, const GameTime game_time) {
    player_movement_.update(input, game_time);

    if(maybe_next_screen_ == nullptr) {
      updateInteractions(input);
    }

    if(player_movement_.moving()) {
      player_.update(player_movement_);

      const Vector2 destination = movementDestination(player_position_, player_movement_.movement());

      const MapCollision map_collision(map_source_->collisionsLayer());
      map_collision.update(player_movement_, player_position_, destination);

      if(!player_movement_.clashing()) {
        map_->update(player_movement_.progress(), player_position_, destination);

        if(player_movement_.finished()) {
          player_position_ = destination;
        }
      }
    } else {
      if(maybe_next_screen_) {
        pushScreen(std::move(maybe_next_screen_));
      } else if(input.startPressed()) {
        pushScreen(std::make_unique<StartScreen>(screenManager()));
      }
    }
  }

  void MapScreen::draw(const Graphics& graphics) const {
    map_->drawBackground(graphics, *map_source_);
    player_.draw(graphics);
    map_->drawForeground(graphics, *map_source_);
  }
}

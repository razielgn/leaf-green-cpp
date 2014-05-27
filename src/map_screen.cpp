#include "map_screen.hpp"

#include "content.hpp"
#include "game_time.hpp"
#include "map.hpp"
#include "map_collision.hpp"
#include "map_source.hpp"
#include "object_interaction.hpp"
#include "player.hpp"
#include "player_input.hpp"
#include "player_movement.hpp"
#include "start_screen.hpp"

#include <iostream>

namespace green_leaf {
  namespace {
    Vector2 movementDestination(const Vector2 start, const Direction movement) {
      switch(movement) {
        case Direction::Right: return start + Vector2(1, 0); break;
        case Direction::Left:  return start - Vector2(1, 0); break;
        case Direction::Up:    return start - Vector2(0, 1); break;
        case Direction::Down:  return start + Vector2(0, 1); break;
        default:              return start; break;
      }
    }
  }

  MapScreen::MapScreen(ScreenManager& screen_manager, const std::string map_name, Vector2 start_pos, Direction direction, const Vector2 screen_size)
    : Screen(screen_manager)
    , map_name_(map_name)
    , screen_size_(screen_size)
    , maybe_next_screen_(nullptr)
    , player_(direction)
    , player_movement_(direction)
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
    if(input.startPressed()) {
      maybe_next_screen_ = std::make_unique<StartScreen>(screenManager());
      return;
    }

    const Vector2 facing = movementDestination(player_position_, player_movement_.direction());

    const ObjectInteraction object_interaction(map_source_->objects());
    maybe_next_screen_ = object_interaction.update(screenManager(), facing, input);
  }

  void MapScreen::update(PlayerInput& input, const GameTime game_time) {
    // When the player is moving nothing can interrupt it from the keyboard.
    // When the player is still or clashing, anything can interrupt it.

    player_movement_.update(input, game_time);

    updateInteractions(input);

    if(player_movement_.moving()) {
      const Vector2 destination = movementDestination(player_position_, player_movement_.direction());

      const MapCollision map_collision(map_source_->collisionsLayer());
      map_collision.update(player_movement_, player_position_, destination);

      if(!player_movement_.clashing()) {
        map_->update(player_movement_.progress(), player_position_, destination);

        if(player_movement_.finished()) {
          player_position_ = destination;
        }
      }
    }

    if(player_movement_.clashing() || !player_movement_.moving()) {
      if(maybe_next_screen_) {
        player_movement_.reset();
        pushScreen(std::move(maybe_next_screen_));
      }
    }

    player_.update(player_movement_, screen_size_ / 2);
  }

  void MapScreen::draw(const Graphics& graphics) const {
    map_->drawBackground(graphics, *map_source_);
    player_.draw(graphics);
    map_->drawForeground(graphics, *map_source_);
  }
}

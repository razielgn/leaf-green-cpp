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
    , clashing_(false)
  {
    player_.position(screen_size_ / 2);
  }

  void MapScreen::loadContent(const Content& content) {
    map_source_ = content.loadMap(map_name_);
    map_collision_ = std::make_unique<const MapCollision>(map_source_->collisionsLayer());

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
    auto screen = object_interaction.update(screenManager(), facing, input);

    if(screen != nullptr) {
      maybe_next_screen_ = std::move(screen);
    }
  }

  void MapScreen::update(PlayerInput& input, const GameTime game_time) {
    switch(player_movement_.state()) {
      case MovementState::Idle: updateIdlePlayer(input); break;
      case MovementState::Turning: updateTurningPlayer(game_time); break;
      case MovementState::Moving: updateMovingPlayer(input, game_time); break;
    }
  }

  void MapScreen::updateIdlePlayer(PlayerInput& input) {
    player_movement_.update(input);

    updateInteractions(input);
    if(maybe_next_screen_) {
      pushScreen(std::move(maybe_next_screen_));
    }
  }

  void MapScreen::updateTurningPlayer(const GameTime game_time) {
    player_timing_.turning(true);
    player_timing_.update(game_time);

    player_.update(player_movement_, player_timing_);

    if(player_timing_.finished()) {
      player_timing_.reset();
      player_movement_.reset();
    }
  }

  void MapScreen::updateMovingPlayer(PlayerInput& input, const GameTime game_time) {
    player_timing_.update(game_time);
    updateInteractions(input);
    player_.update(player_movement_, player_timing_);

    Vector2 destination = movementDestination(player_position_, player_movement_.direction());
    clashing_ = !map_collision_->canMove(player_position_, destination);

    player_timing_.clashing(clashing_);

    if(clashing_) {
      destination = player_position_;
    }

    map_->update(player_timing_.progress(), player_position_, destination);

    if(player_timing_.finished()) {
      player_timing_.reset();
      player_movement_.update(input);

      player_position_ = destination;
    }

    if(clashing_ && maybe_next_screen_) {
      player_movement_.reset();
      player_timing_.reset();
      player_.update(player_movement_, player_timing_);
      pushScreen(std::move(maybe_next_screen_));
    }
  }

  void MapScreen::draw(const Graphics& graphics) const {
    map_->drawBackground(graphics, *map_source_);
    player_.draw(graphics);
    map_->drawForeground(graphics, *map_source_);
  }
}

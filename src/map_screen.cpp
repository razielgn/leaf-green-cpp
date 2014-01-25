#include "content.hpp"
#include "map.hpp"
#include "map_screen.hpp"
#include "player.hpp"
#include "player_movement.hpp"
#include "player_movement.hpp"

namespace green_leaf {
  MapScreen::MapScreen(std::string map_name, Vector2 start_pos, Vector2 screen_size)
    : map_name_(map_name)
    , start_pos_(start_pos)
    , screen_size_(screen_size)
  {
    player_ = new Player();
    player_movement_ = new PlayerMovement();
  }

  MapScreen::~MapScreen() {
    delete player_;
    delete map_;
    delete player_movement_;
  }

  void MapScreen::loadContent(const Content* content) {
    player_->loadContent(content);

    map_ = new Map(content->loadMap(map_name_), start_pos_, screen_size_);
  }

  void MapScreen::update(Input* input, const GameTime* game_time) {
    player_movement_->update(input, game_time);

    player_->update(player_movement_);
    map_->update(player_movement_);
  }

  void MapScreen::draw(const Graphics* graphics) const {
    map_->drawBackground(graphics);
    player_->draw(graphics);
    map_->drawForeground(graphics);
  }
}

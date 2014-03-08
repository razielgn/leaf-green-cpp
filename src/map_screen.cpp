#include "map_screen.hpp"

#include "content.hpp"
#include "game_time.hpp"
#include "map.hpp"
#include "map_source.hpp"
#include "player.hpp"
#include "player_movement.hpp"
#include "player_movement.hpp"

namespace green_leaf {
  MapScreen::MapScreen(std::string map_name, Vector2 start_pos, Vector2 screen_size)
    : map_name_(map_name)
    , start_pos_(start_pos)
    , screen_size_(screen_size)
  {
  }

  void MapScreen::loadContent(const Content& content) {
    map_source_ = std::unique_ptr<const MapSource>(content.loadMap(map_name_));
    player_.loadContent(content);

    map_ = std::unique_ptr<Map>(new Map(*map_source_, start_pos_, screen_size_));
  }

  void MapScreen::update(Input& input, const GameTime game_time) {
    player_movement_.update(input, game_time);

    player_.update(player_movement_);
    map_->update(player_movement_, *map_source_->collisionsLayer());
  }

  void MapScreen::draw(const Graphics& graphics) const {
    map_->drawBackground(graphics, *map_source_);
    player_.draw(graphics);
    map_->drawForeground(graphics, *map_source_);
  }
}

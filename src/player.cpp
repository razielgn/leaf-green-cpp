#include "player.hpp"

namespace green_leaf {
  void Player::loadContent(const Content& content) {
    animation_.loadContent(content);
  }

  void Player::update(const PlayerMovement& player_movement) {
    animation_.update(player_movement);
  }

  void Player::draw(const Graphics& graphics) const {
    animation_.draw(graphics);
  }
}

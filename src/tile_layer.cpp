#include "graphics.hpp"
#include "vector2.hpp"
#include "rectangle.hpp"
#include "tile_layer.hpp"
#include "tile_set.hpp"

namespace green_leaf {
  TileLayer::TileLayer(Vector2 size, std::string name, std::vector<unsigned int> tiles)
    : size_(size)
    , name_(name)
    , tiles_(tiles)
  {
  }

  TileLayer::~TileLayer() {
  }

  void TileLayer::draw(const Graphics* graphics, const TileSet* tile_set, const Vector2 offset) const {
    Vector2 tile_size = tile_set->tile_size();

    // OPTIMIZATION: Only draw visible tiles.
    for(unsigned int i = 0; i < size_.y(); i++) {
      for(unsigned int j = 0; j < size_.x(); j++) {
        unsigned int tile_code = tiles_[j + size_.x() * i];

        if(tile_code > 0) {
          Rectangle tile = tile_set->rectangleFromCode(tile_code);
          Vector2 destOffset = Vector2(j, i) * tile_size + offset;

          graphics->drawTexture(
            tile_set->texture(),
            Rectangle(destOffset, tile_size),
            tile.scaleOrigin(tile_size)
          );
        }
      }
    }
  }
}

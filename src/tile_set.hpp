#ifndef GL_TILE_SET_HPP
#define GL_TILE_SET_HPP

#include "rectangle.hpp"
#include "vector2.hpp"

#include <memory>

namespace green_leaf {
  class Texture;

  class TileSet {
  public:
    TileSet(std::unique_ptr<const Texture> texture, const Vector2 tile_size, unsigned int start_code);
    TileSet(const TileSet& other);

    Rectangle rectangleFromCode(unsigned int tile_code) const;

    const Texture& texture() const {
      return *texture_;
    }

    const Vector2 tileSize() const {
      return tile_size_;
    }

    unsigned int startCode() const {
      return start_code_;
    }

  private:
    const Vector2 tile_grid_;
    const Vector2 tile_size_;
    const std::unique_ptr<const Texture> texture_;

    const unsigned int start_code_;
  };
}

#endif

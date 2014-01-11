#ifndef GL_TILE_LAYER_HPP
#define GL_TILE_LAYER_HPP

#include <vector>

#include "layer.hpp"
#include "vector2.hpp"

namespace green_leaf {
  class TileLayer : public Layer {
  public:
    TileLayer(Vector2 size, std::string name, std::vector<unsigned int> tiles);
    ~TileLayer();

    std::string name() const {
      return name_;
    }

    Vector2 size() const {
      return size_;
    }

    void draw(const Graphics* graphics, const TileSet* tile_set, const Vector2 offset) const;

  private:
    const Vector2 size_;
    const std::string name_;
    const std::vector<unsigned int> tiles_;
  };
}

#endif

#ifndef GL_COLLISIONS_LAYER_HPP
#define GL_COLLISIONS_LAYER_HPP

#include "rectangle.hpp"
#include <vector>

namespace green_leaf {
  class CollisionsLayer {
  public:
    CollisionsLayer(const std::vector<Rectangle> rectangles);

    std::vector<Rectangle> rectangles() const {
      return rectangles_;
    }

  private:
    const std::vector<Rectangle> rectangles_;
  };
}

#endif

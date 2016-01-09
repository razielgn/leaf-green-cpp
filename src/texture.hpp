#pragma once

#include "vector2.hpp"

namespace green_leaf {
  class Texture {
  public:
    virtual ~Texture() { }

    virtual Vector2 size() const = 0;
  };
}

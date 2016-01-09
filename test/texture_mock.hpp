#pragma once

#include "texture.hpp"

namespace green_leaf {
  class TextureMock : public Texture {
  public:
    TextureMock(Vector2 size)
      : size_(size)
    {
    }

    Vector2 size() const override {
      return size_;
    }

  private:
    const Vector2 size_;
  };
}

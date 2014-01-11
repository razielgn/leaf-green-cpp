#ifndef GL_TEXTURE_MOCK_HPP
#define GL_TEXTURE_MOCK_HPP

#include "texture.hpp"

namespace green_leaf {
  class TextureMock : public Texture {
  public:
    TextureMock(Vector2 size)
      : size_(size)
    {
    }

    Vector2 size() const {
      return size_;
    }

  private:
    const Vector2 size_;
  };
}

#endif

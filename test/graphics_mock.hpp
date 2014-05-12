#pragma once
#ifndef GL_GRAPHICS_MOCK_HPP
#define GL_GRAPHICS_MOCK_HPP

#include "gmock/gmock.h"
#include "graphics.hpp"

namespace green_leaf {
  class GraphicsMock : public Graphics {
  public:
    GraphicsMock() { }
    GraphicsMock(const GraphicsMock& other);
    ~GraphicsMock() { }

    MOCK_CONST_METHOD0(clear, void());
    MOCK_CONST_METHOD3(drawTexture, void(const Texture& texture, const Rectangle destination, const Rectangle source));
    MOCK_CONST_METHOD2(drawTexture, void(const Texture& texture, const Rectangle destination));
    MOCK_CONST_METHOD3(drawTexture, void(const Texture& texture, const Vector2 offset, const Rectangle source));
    MOCK_CONST_METHOD0(present, void());
    MOCK_CONST_METHOD0(size, Vector2());
  };
}

#endif

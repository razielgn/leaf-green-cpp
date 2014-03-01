#ifndef GL_SCREEN_MOCK_HPP
#define GL_SCREEN_MOCK_HPP

#include "screen.hpp"

#include "gmock/gmock.h"

namespace green_leaf {
  class ScreenMock : public Screen {
  public:
    ScreenMock() { }
    ~ScreenMock() { }

    MOCK_METHOD1(loadContent, void(const Content* content));
    MOCK_METHOD2(update, void(Input* input, const GameTime* game_time));
    MOCK_CONST_METHOD1(draw, void(const Graphics* graphics));
  };
}

#endif

#pragma once
#ifndef GL_PLAYER_INPUT_MOCK_HPP
#define GL_PLAYER_INPUT_MOCK_HPP

#include "gmock/gmock.h"
#include "player_input.hpp"

namespace green_leaf {
  class PlayerInputMock : public PlayerInput {
  public:
    void update() { }

    MOCK_CONST_METHOD0(a, bool());
    MOCK_CONST_METHOD0(aPressed, bool());
    MOCK_CONST_METHOD0(b, bool());
    MOCK_CONST_METHOD0(bPressed, bool());
    MOCK_CONST_METHOD0(up, bool());
    MOCK_CONST_METHOD0(upPressed, bool());
    MOCK_CONST_METHOD0(down, bool());
    MOCK_CONST_METHOD0(downPressed, bool());
    MOCK_CONST_METHOD0(left, bool());
    MOCK_CONST_METHOD0(right, bool());
    MOCK_CONST_METHOD0(start, bool());
    MOCK_CONST_METHOD0(startPressed, bool());
    MOCK_CONST_METHOD0(select, bool());
    MOCK_CONST_METHOD0(l, bool());
    MOCK_CONST_METHOD0(r, bool());
    MOCK_CONST_METHOD0(escape, bool());
  };
}

#endif

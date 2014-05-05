#ifndef GL_INPUT_MOCK_HPP
#define GL_INPUT_MOCK_HPP

#include "gmock/gmock.h"
#include "keyboard_input.hpp"
#include "input_key.hpp"

namespace green_leaf {
  class KeyboardInputMock : public KeyboardInput {
  public:
    KeyboardInputMock() { }
    KeyboardInputMock(const KeyboardInputMock& other);
    ~KeyboardInputMock() { }

    MOCK_METHOD0(recordState, void());
    MOCK_METHOD1(isKeyDown, bool(InputKey key));
    MOCK_METHOD1(isKeyUp, bool(InputKey key));
  };
}

#endif

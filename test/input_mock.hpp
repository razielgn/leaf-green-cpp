#ifndef GL_INPUT_MOCK_HPP
#define GL_INPUT_MOCK_HPP

#include "gmock/gmock.h"
#include "input.hpp"
#include "input_key.hpp"

namespace green_leaf {
  class InputMock : public Input {
  public:
    InputMock() { }
    InputMock(const InputMock& other);
    ~InputMock() { }

    MOCK_METHOD0(recordState, void());
    MOCK_METHOD0(hasQuit, bool());
    MOCK_METHOD1(isKeyDown, bool(InputKey key));
    MOCK_METHOD1(isKeyUp, bool(InputKey key));
  };
}

#endif

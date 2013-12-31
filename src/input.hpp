#ifndef GL_INPUT_HPP
#define GL_INPUT_HPP

#include "input_key.hpp"

namespace green_leaf {
  class Input {
  public:
    virtual ~Input() { };

    virtual void recordState() = 0;

    virtual bool isKeyUp(InputKey key) = 0;
    virtual bool isKeyDown(InputKey key) = 0;

    virtual bool hasQuit() = 0;
  };
}

#endif

#pragma once
#ifndef GL_KEYBOARD_INPUT_HPP
#define GL_KEYBOARD_INPUT_HPP

namespace green_leaf {
  enum class InputKey;

  class KeyboardInput {
  public:
    virtual ~KeyboardInput() { }

    virtual void recordState() = 0;

    virtual bool isKeyUp(InputKey key) = 0;
    virtual bool isKeyDown(InputKey key) = 0;
  };
}

#endif

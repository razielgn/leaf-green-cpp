#pragma once
#ifndef GL_KEYBOARD_INPUT_HPP
#define GL_KEYBOARD_INPUT_HPP

namespace green_leaf {
  enum class InputKey;

  class KeyboardInput {
  public:
    virtual ~KeyboardInput() { }

    virtual void recordState() = 0;

    virtual bool isKeyUp(InputKey key) const = 0;
    virtual bool isKeyDown(InputKey key) const = 0;
  };
}

#endif

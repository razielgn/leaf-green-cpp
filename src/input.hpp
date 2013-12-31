#ifndef GL_INPUT_HPP
#define GL_INPUT_HPP

namespace green_leaf {
  enum class InputKey;

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

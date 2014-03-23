#ifndef GL_OBJECT_HPP
#define GL_OBJECT_HPP

#include "custom_types.hpp"
#include "rectangle.hpp"

#include <vector>

namespace green_leaf {
  class Object {
  public:
    Object(const Rectangle rect, const std::vector<message> messages)
      : rectangle_(rect)
      , messages_(messages)
    {
    }

    const Rectangle rectangle() const {
      return rectangle_;
    }

    const std::vector<message> messages() const {
      return messages_;
    }

  private:
    const Rectangle rectangle_;
    const std::vector<message> messages_;
  };
}

#endif

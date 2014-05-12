#pragma once
#ifndef GL_OBJECT_HPP
#define GL_OBJECT_HPP

#include "custom_types.hpp"
#include "rectangle.hpp"

#include <vector>

namespace green_leaf {
  class Object {
  public:
    Object(const Rectangle rect, const std::vector<message> messages, bool sign)
      : rectangle_(rect)
      , messages_(messages)
      , sign_(sign)
    {
    }

    const Rectangle rectangle() const {
      return rectangle_;
    }

    bool isSign() const {
      return sign_;
    }

    const std::vector<message> messages() const {
      return messages_;
    }

  private:
    const Rectangle rectangle_;
    const std::vector<message> messages_;
    const bool sign_;
  };
}

#endif

#ifndef GL_RECTANGLE_HPP
#define GL_RECTANGLE_HPP

#include <SDL.h>
#include <iostream>
#include <string>

#include "vector2.hpp"

namespace green_leaf {
  class Rectangle {
  public:
    Rectangle(int x, int y, int width, int height);
    Rectangle(int x, int y, Vector2 size);
    Rectangle(Vector2 origin, int width, int height);
    Rectangle(Vector2 origin, Vector2 size);

    Rectangle scaleOrigin(Vector2 vec) const;
    const SDL_Rect toSDLRect() const;

    std::string toString() const;

    Rectangle operator*(int factor) const;

    Vector2 origin() const {
      return origin_;
    }

    Vector2 size() const {
      return size_;
    }


    bool operator==(const Rectangle& r) const {
      return (this == &r) || (
        origin_ == r.origin_ &&
        size_   == r.size_
      );
    }

    bool operator!=(const Rectangle& r) const {
      return !(*this == r);
    }

  private:
    Vector2 origin_;
    Vector2 size_;
  };

  ::std::ostream& operator<<(::std::ostream& os, const Rectangle& r);
}

#endif

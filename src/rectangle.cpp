#include "rectangle.hpp"

#include <sstream>

namespace green_leaf {
  Rectangle::Rectangle(int x, int y, int width, int height)
    : Rectangle(Vector2(x, y), Vector2(width, height))
  {
  }

  Rectangle::Rectangle(int x, int y, Vector2 size)
    : Rectangle(Vector2(x, y), size)
  {
  }

  Rectangle::Rectangle(Vector2 origin, int width, int height)
    : Rectangle(origin, Vector2(width, height))
  {
  }

  Rectangle::Rectangle(Vector2 origin, Vector2 size)
    : origin_(origin)
    , size_(size)
  {
  }

  Rectangle Rectangle::scale(int f) const {
    return Rectangle(
      origin_ * f,
      size_ * f
    );
  }

  const SDL_Rect Rectangle::toSDLRect() const {
    SDL_Rect rect;

    rect.x = origin_.x();
    rect.y = origin_.y();
    rect.w = size_.x();
    rect.h = size_.y();

    return rect;
  }

  std::string Rectangle::toString() const {
    std::stringstream s;
    s << "Rectangle("
      << origin_.x() << ", "
      << origin_.y() << ", "
      << size_.x()   << ", "
      << size_.y()   << ")";
    return s.str();
  }

  ::std::ostream& operator<<(::std::ostream& os, const Rectangle& r) {
    return os << r.toString();
  }
}

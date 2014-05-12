#include "vector2.hpp"

#include <iostream>
#include <sstream>

namespace green_leaf {
  Vector2::Vector2(int x, int y)
    : x_(x)
    , y_(y)
  {
  }

  Vector2 Vector2::operator+(const Vector2& p) const {
    return Vector2(
      x_ + p.x_,
      y_ + p.y_
    );
  }

  Vector2 Vector2::operator-(const Vector2& p) const {
    return Vector2(
      x_ - p.x_,
      y_ - p.y_
    );
  }

  Vector2 Vector2::operator*(int f) const {
    return Vector2(
      x_ * f,
      y_ * f
    );
  }

  Vector2 Vector2::operator*(const Vector2& p) const {
    return Vector2(
      x_ * p.x_,
      y_ * p.y_
    );
  }

  Vector2 Vector2::operator/(int f) const {
    return Vector2(
      x_ / f,
      y_ / f
    );
  }

  Vector2 Vector2::operator/(const Vector2& p) const {
    return Vector2(
      x_ / p.x_,
      y_ / p.y_
    );
  }

  std::string Vector2::toString() const {
    std::stringstream s;
    s << "Vector2(" << x_ << ", " << y_ << ")";
    return s.str();
  }

  ::std::ostream& operator<<(::std::ostream& os, const Vector2& v) {
    return os << v.toString();
  }
}

#include "vector2f.hpp"

#include <sstream>

namespace green_leaf {
  Vector2f::Vector2f(float x, float y)
    : x_(x)
    , y_(y)
  {
  }

  Vector2f::Vector2f(Vector2 vector)
    : x_((float)vector.x())
    , y_((float)vector.y())
  {
  }

  Vector2f Vector2f::operator+(const Vector2f& p) const {
    return Vector2f(
      x_ + p.x_,
      y_ + p.y_
    );
  }

  Vector2f Vector2f::operator-(const Vector2f& p) const {
    return Vector2f(
      x_ - p.x_,
      y_ - p.y_
    );
  }

  Vector2f Vector2f::operator*(float f) const {
    return Vector2f(
      x_ * f,
      y_ * f
    );
  }

  Vector2f Vector2f::operator*(const Vector2f& p) const {
    return Vector2f(
      x_ * p.x_,
      y_ * p.y_
    );
  }

  Vector2f Vector2f::operator/(float f) const {
    return Vector2f(
      x_ / f,
      y_ / f
    );
  }

  Vector2f Vector2f::operator/(const Vector2f& p) const {
    return Vector2f(
      x_ / p.x_,
      y_ / p.y_
    );
  }

  std::string Vector2f::toString() const {
    std::stringstream s;
    s << "Vector2f(" << x_ << ", " << y_ << ")";
    return s.str();
  }

  Vector2 Vector2f::toVector2() const {
    return Vector2(
      (int)x_,
      (int)y_
    );
  }

  ::std::ostream& operator<<(::std::ostream& os, const Vector2f& v) {
    return os << v.toString();
  }
}

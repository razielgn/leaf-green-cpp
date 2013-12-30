#include "point.hpp"

#include <sstream>

namespace green_leaf {
  Point::Point(float x, float y)
    : x_(x)
    , y_(y)
  {
  }

  Point Point::operator+(const Point& p) const {
    return Point(
      x_ + p.x_,
      y_ + p.y_
    );
  }

  Point Point::operator-(const Point& p) const {
    return Point(
      x_ - p.x_,
      y_ - p.y_
    );
  }

  Point Point::operator*(float f) const {
    return Point(
      x_ * f,
      y_ * f
    );
  }

  std::string Point::toString() const {
    std::stringstream s;
    s << "Point(" << x_ << ", " << y_ << ")";
    return s.str();
  }

  void PrintTo(const Point& p, std::ostream* os) {
    *os << p.toString();
  }
}

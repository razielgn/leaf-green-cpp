#include "point.hpp"

#include <sstream>

namespace green_leaf {
  Point::Point(int x, int y)
    : x_(x)
    , y_(y)
  {
  }

  std::string Point::toString() const {
    std::stringstream s;
    s << "Point(" << x_ << ", " << y_ << ")";
    return s.str();
  }
}

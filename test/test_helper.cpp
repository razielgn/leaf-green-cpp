#include "point.hpp"
#include "test_helper.hpp"

#include <string>

namespace green_leaf {
  void PrintTo(const Point& p, std::ostream* os) {
    *os << p.toString();
  }
}

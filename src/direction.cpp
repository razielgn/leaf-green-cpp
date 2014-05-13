#include "direction.hpp"

#include <iostream>

namespace green_leaf {
  ::std::ostream& operator<<(::std::ostream& os, const Direction& m) {
    switch(m) {
      case Direction::Right: return os << "Right"; break;
      case Direction::Left:  return os << "Left"; break;
      case Direction::Up:    return os << "Up"; break;
      case Direction::Down:  return os << "Down"; break;
    }

    return os;
  }
}

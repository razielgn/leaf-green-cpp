#include <iostream>

namespace green_leaf {
  enum class InputKey;
  class Point;
  class Rectangle;

  void PrintTo(const InputKey& p, std::ostream* os);
  void PrintTo(const Point& p, std::ostream* os);
  void PrintTo(const Rectangle& p, std::ostream* os);
}

#include <iostream>

namespace green_leaf {
  enum class InputKey;
  class Vector2;
  class Rectangle;

  void PrintTo(const InputKey& p, std::ostream* os);
  void PrintTo(const Vector2& p, std::ostream* os);
  void PrintTo(const Rectangle& p, std::ostream* os);
}

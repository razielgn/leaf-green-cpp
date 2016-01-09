#pragma once

#include <iosfwd>

namespace green_leaf {
  enum class InputKey {
    A,
    B,
    Up,
    Down,
    Left,
    Right,
    Start,
    Select,
    R,
    L,
    Escape,
  };

  ::std::ostream& operator<<(::std::ostream& os, const InputKey& p);
}

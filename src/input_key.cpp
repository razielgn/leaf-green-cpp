#include "input_key.hpp"

namespace green_leaf {
  ::std::ostream& operator<<(::std::ostream& os, const InputKey& p) {
    std::string str;

    switch(p) {
      case InputKey::A:      str = "InputKey::A";      break;
      case InputKey::B:      str = "InputKey::B";      break;
      case InputKey::Down:   str = "InputKey::Down";   break;
      case InputKey::Escape: str = "InputKey::Escape"; break;
      case InputKey::L:      str = "InputKey::L";      break;
      case InputKey::Left:   str = "InputKey::Left";   break;
      case InputKey::R:      str = "InputKey::R";      break;
      case InputKey::Right:  str = "InputKey::Right";  break;
      case InputKey::Select: str = "InputKey::Select"; break;
      case InputKey::Start:  str = "InputKey::Start";  break;
      case InputKey::Up:     str = "InputKey::Up";     break;
    }

    return os << str;
  }

}

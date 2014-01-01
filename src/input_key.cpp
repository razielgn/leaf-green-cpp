#include "input_key.hpp"

namespace green_leaf {
  ::std::ostream& operator<<(::std::ostream& os, const InputKey& p) {
    std::string str;

    switch(p) {
      case InputKey::A:      str = std::string("InputKey::A");      break;
      case InputKey::B:      str = std::string("InputKey::B");      break;
      case InputKey::Down:   str = std::string("InputKey::Down");   break;
      case InputKey::Escape: str = std::string("InputKey::Escape"); break;
      case InputKey::L:      str = std::string("InputKey::L");      break;
      case InputKey::Left:   str = std::string("InputKey::Left");   break;
      case InputKey::R:      str = std::string("InputKey::R");      break;
      case InputKey::Right:  str = std::string("InputKey::Right");  break;
      case InputKey::Select: str = std::string("InputKey::Select"); break;
      case InputKey::Start:  str = std::string("InputKey::Start");  break;
      case InputKey::Up:     str = std::string("InputKey::Up");     break;
    }

    return os << str;
  }

}

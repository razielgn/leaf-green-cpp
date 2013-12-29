#include "game_time.hpp"

namespace green_leaf {
  GameTime::GameTime(const unsigned int elapsed, const unsigned int total)
    : elapsed_(elapsed)
    , total_(total)
  {
  }
}

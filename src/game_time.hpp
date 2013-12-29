#ifndef GL_GAME_TIME_HPP
#define GL_GAME_TIME_HPP

namespace green_leaf {
  class GameTime {
  public:
    GameTime(const unsigned int elapsed, const unsigned int total);

    unsigned int elapsed() const {
      return elapsed_;
    }

    unsigned int total() const {
      return total_;
    }

  private:
    unsigned int elapsed_;
    unsigned int total_;
  };
}

#endif

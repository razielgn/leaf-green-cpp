#pragma once
#ifndef GL_MOVEMENT_TIMING
#define GL_MOVEMENT_TIMING

namespace green_leaf {
  class GameTime;

  class MovementTiming {
  public:
    MovementTiming();

    void clashing(const bool clashing) {
      clashing_ = clashing;
    }

    bool clashing() const {
      return clashing_;
    }

    void turning(const bool turning) {
      turning_ = turning;
    }

    bool finished() const;
    float progress() const;
    void reset();
    void update(const GameTime game_time);

  private:
    unsigned int elapsed_;
    bool clashing_;
    bool turning_;
  };
}

#endif

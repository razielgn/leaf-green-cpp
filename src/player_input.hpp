#pragma once
#ifndef GL_PLAYER_INPUT_HPP
#define GL_PLAYER_INPUT_HPP

namespace green_leaf {
  class PlayerInput {
  public:
    virtual void update() = 0;

    virtual bool a() const = 0;
    virtual bool aPressed() const = 0;
    virtual bool b() const = 0;
    virtual bool bPressed() const = 0;
    virtual bool up() const = 0;
    virtual bool upPressed() const = 0;
    virtual bool down() const = 0;
    virtual bool downPressed() const = 0;
    virtual bool left() const = 0;
    virtual bool right() const = 0;
    virtual bool start() const = 0;
    virtual bool startPressed() const = 0;
    virtual bool select() const = 0;
    virtual bool r() const = 0;
    virtual bool l() const = 0;
    virtual bool escape() const = 0;
  };
}

#endif

#ifndef GL_POINT_HPP
#define GL_POINT_HPP

#include <iostream>
#include <string>

namespace green_leaf {
  class Vector2 {
  public:
    Vector2(float x, float y);

    std::string toString() const;

    float x() const {
      return x_;
    }

    float y() const {
      return y_;
    }

    bool operator==(const Vector2& p) const {
      return (this == &p) || (x_ == p.x_ && y_ == p.y_);
    }

    bool operator!=(const Vector2& p) const {
      return !(*this == p);
    }

    Vector2 operator+(const Vector2& p) const;
    Vector2 operator-(const Vector2& p) const;
    Vector2 operator*(float f) const;
    Vector2 operator*(const Vector2& p) const;
    Vector2 operator/(float f) const;
    Vector2 operator/(const Vector2& p) const;

  private:
    float x_;
    float y_;
  };

  ::std::ostream& operator<<(::std::ostream& os, const Vector2& v);
}

#endif
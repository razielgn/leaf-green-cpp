#ifndef GL_VECTOR2F_HPP
#define GL_VECTOR2F_HPP

#include "vector2.hpp"

#include <cmath>
#include <iostream>
#include <limits>
#include <string>

namespace green_leaf {
  class Vector2f {
  public:
    Vector2f(float x, float y);
    Vector2f(Vector2 vector);

    std::string toString() const;
    Vector2 toVector2() const;

    float x() const {
      return x_;
    }

    float y() const {
      return y_;
    }

    bool operator==(const Vector2f& p) const {
#define FLOAT_EQ(x, y) (std::fabs((x) - (y)) < std::numeric_limits<float>::epsilon())
      return (this == &p) || (FLOAT_EQ(x_, p.x_) && FLOAT_EQ(y_, p.y_));
#undef FLOAT_EQ
    }

    bool operator!=(const Vector2f& p) const {
      return !(*this == p);
    }

    Vector2f operator+(const Vector2f& p) const;
    Vector2f operator-(const Vector2f& p) const;
    Vector2f operator*(float f) const;
    Vector2f operator*(const Vector2f& p) const;
    Vector2f operator/(float f) const;
    Vector2f operator/(const Vector2f& p) const;

  private:
    float x_;
    float y_;
  };

  ::std::ostream& operator<<(::std::ostream& os, const Vector2f& v);
}

namespace std {
  template <> struct hash<green_leaf::Vector2f> {
    size_t operator()(const green_leaf::Vector2f &v) const {
      std::hash<float> hasher;
      return hasher(v.x()) ^ hasher(v.y());
    }
  };
}

#endif

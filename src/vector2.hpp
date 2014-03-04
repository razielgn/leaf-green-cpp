#ifndef GL_VECTOR2_HPP
#define GL_VECTOR2_HPP

#include <iostream>
#include <string>

namespace green_leaf {
  class Vector2 {
  public:
    Vector2(int x, int y);

    std::string toString() const;

    int x() const {
      return x_;
    }

    int y() const {
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
    Vector2 operator*(int f) const;
    Vector2 operator*(const Vector2& p) const;
    Vector2 operator/(int f) const;
    Vector2 operator/(const Vector2& p) const;

  private:
    int x_;
    int y_;
  };

  ::std::ostream& operator<<(::std::ostream& os, const Vector2& v);
}

namespace std {
  template <> struct hash<green_leaf::Vector2> {
    size_t operator()(const green_leaf::Vector2 &v) const {
      std::hash<int> hasher;
      return hasher(v.x()) ^ hasher(v.y());
    }
  };
}

#endif

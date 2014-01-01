#ifndef GL_POINT_HPP
#define GL_POINT_HPP

#include <string>

namespace green_leaf {
  class Point {
  public:
    Point(float x, float y);

    std::string toString() const;

    float x() const {
      return x_;
    }

    float y() const {
      return y_;
    }

    bool operator==(const Point& p) const {
      return (this == &p) || (x_ == p.x_ && y_ == p.y_);
    }

    bool operator!=(const Point& p) const {
      return !(*this == p);
    }

    Point operator+(const Point& p) const;
    Point operator-(const Point& p) const;
    Point operator*(float f) const;
    Point operator*(const Point& p) const;
    Point operator/(const Point& p) const;

  private:
    float x_;
    float y_;
  };
}

#endif

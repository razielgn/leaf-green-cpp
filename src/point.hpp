#ifndef GL_POINT_HPP
#define GL_POINT_HPP

#include <iostream>
#include <string>

namespace green_leaf {
  class Point {
  public:
    Point(int x, int y);

    std::string toString() const;

    int x() const {
      return x_;
    }

    int y() const {
      return y_;
    }

    bool operator==(const Point& p) const {
      return (this == &p) || (x_ == p.x_ && y_ == p.y_);
    }

    bool operator!=(const Point& p) const {
      return !(*this == p);
    }

  private:
    int x_;
    int y_;
  };

  void PrintTo(const Point& p, std::ostream* os);
}

#endif

#ifndef GL_POINT_HPP
#define GL_POINT_HPP

namespace green_leaf {
  class Point {
  public:
    Point(int x, int y);

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
    const int x_;
    const int y_;
  };
}

#endif

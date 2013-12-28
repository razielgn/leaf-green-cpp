#ifndef GL_RECTANGLE_HPP
#define GL_RECTANGLE_HPP

#include <SDL.h>

namespace green_leaf {
  class Rectangle {
  public:
    Rectangle(int x, int y, int width, int height);

    Rectangle scale(int factor) const;
    SDL_Rect toSDLRect() const;

    int x() const {
      return x_;
    }

    int y() const {
      return y_;
    }

    int width() const {
      return width_;
    }

    int height() const {
      return height_;
    }

    bool operator==(const Rectangle& rect) const {
      return (
        x_ == rect.x_ &&
        y_ == rect.y_ &&
        width_ == rect.width_ &&
        height_ == rect.height_
      );
    }

    bool operator!=(const Rectangle& rect) const {
      return !(*this == rect);
    }

  private:
    int x_;
    int y_;
    int width_;
    int height_;
  };
}

#endif

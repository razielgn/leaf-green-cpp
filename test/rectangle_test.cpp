#include "gtest/gtest.h"
#include "point.hpp"
#include "rectangle.hpp"

namespace green_leaf {
  class RectangleTest : public ::testing::Test {
  protected:
    RectangleTest() :
      rect_(Rectangle(1, 2, 3, 4))
    {
    }

    const Rectangle rect_;
  };

  TEST_F(RectangleTest, DefaultConstructor) {
    EXPECT_EQ(1, rect_.x());
    EXPECT_EQ(2, rect_.y());
    EXPECT_EQ(3, rect_.width());
    EXPECT_EQ(4, rect_.height());
  }

  TEST_F(RectangleTest, ConstructorWithPointAndIntegers) {
    Rectangle r(Point(1, 2), 3, 4);

    EXPECT_EQ(1, r.x());
    EXPECT_EQ(2, r.y());
    EXPECT_EQ(3, r.width());
    EXPECT_EQ(4, r.height());
  }

  TEST_F(RectangleTest, ConstructorWithIntegersAndPoint) {
    Rectangle r(1, 2, Point(3, 4));

    EXPECT_EQ(1, r.x());
    EXPECT_EQ(2, r.y());
    EXPECT_EQ(3, r.width());
    EXPECT_EQ(4, r.height());
  }

  TEST_F(RectangleTest, ConstructorWithPoints) {
    Rectangle r(Point(1, 2), Point(3, 4));

    EXPECT_EQ(1, r.x());
    EXPECT_EQ(2, r.y());
    EXPECT_EQ(3, r.width());
    EXPECT_EQ(4, r.height());
  }

  TEST_F(RectangleTest, Identity) {
    EXPECT_EQ(rect_, rect_);
  }

  TEST_F(RectangleTest, Equality) {
    EXPECT_EQ(Rectangle(1, 2, 3, 4), rect_);
  }

  TEST_F(RectangleTest, Inequality) {
    EXPECT_NE(Rectangle(1, 2, 3, 1), rect_);
  }

  TEST_F(RectangleTest, Scale) {
    EXPECT_EQ(Rectangle(0, 0, 0, 0), rect_.scale(0));
    EXPECT_EQ(Rectangle(2, 4, 6, 8), rect_.scale(2));

    EXPECT_EQ(rect_, rect_.scale(1));
  }

  TEST_F(RectangleTest, ToSDLRect) {
    const SDL_Rect rect = rect_.toSDLRect();

    EXPECT_EQ(1, rect.x);
    EXPECT_EQ(2, rect.y);
    EXPECT_EQ(3, rect.w);
    EXPECT_EQ(4, rect.h);
  }

  TEST_F(RectangleTest, ToString) {
    EXPECT_EQ(std::string("Rectangle(1, 2, 3, 4)"), rect_.toString());
  }
}

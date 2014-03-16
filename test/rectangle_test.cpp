#include "gtest/gtest.h"
#include "vector2.hpp"
#include "rectangle.hpp"

namespace green_leaf {
  TEST(RectangleTest, DefaultConstructor) {
    Rectangle r(1, 2, 3, 4);

    EXPECT_EQ(Vector2(1, 2), r.origin());
    EXPECT_EQ(Vector2(3, 4), r.size());
  }

  TEST(RectangleTest, ConstructorWithVector2AndIntegers) {
    Rectangle r(Vector2(1, 2), 3, 4);

    EXPECT_EQ(Vector2(1, 2), r.origin());
    EXPECT_EQ(Vector2(3, 4), r.size());
  }

  TEST(RectangleTest, ConstructorWithIntegersAndVector2) {
    Rectangle r(1, 2, Vector2(3, 4));

    EXPECT_EQ(Vector2(1, 2), r.origin());
    EXPECT_EQ(Vector2(3, 4), r.size());
  }

  TEST(RectangleTest, ConstructorWithVector2s) {
    Rectangle r(Vector2(1, 2), Vector2(3, 4));

    EXPECT_EQ(Vector2(1, 2), r.origin());
    EXPECT_EQ(Vector2(3, 4), r.size());
  }

  TEST(RectangleTest, Origin) {
    EXPECT_EQ(Vector2(1, 2), Rectangle(1, 2, 3, 4).origin());
  }

  TEST(RectangleTest, Size) {
    EXPECT_EQ(Vector2(3, 4), Rectangle(1, 2, 3, 4).size());
  }

  TEST(RectangleTest, Identity) {
    Rectangle r(1, 2, 3, 4);

    EXPECT_EQ(r, r);
  }

  TEST(RectangleTest, Equality) {
    EXPECT_EQ(Rectangle(1, 2, 3, 4), Rectangle(1, 2, 3, 4));
  }

  TEST(RectangleTest, Inequality) {
    EXPECT_NE(Rectangle(1, 2, 3, 1), Rectangle(1, 2, 3, 4));
  }

  TEST(RectangleTest, MultiplicationByScalar) {
    Rectangle r(1, 2, 3, 4);

    EXPECT_EQ(Rectangle(0, 0, 0, 0), r * 0);
    EXPECT_EQ(Rectangle(1, 2, 3, 4), r * 1);
    EXPECT_EQ(Rectangle(2, 4, 6, 8), r * 2);
  }

  TEST(RectangleTest, DivisionByVector) {
    Rectangle r(2, 4, 6, 8);

    EXPECT_EQ(Rectangle(2, 2, 6, 4), r / Vector2(1, 2));
    EXPECT_EQ(Rectangle(1, 1, 3, 2), r / Vector2(2, 4));
  }

  TEST(RectangleTest, ToSDLRect) {
    const SDL_Rect rect = Rectangle(1, 2, 3, 4).toSDLRect();

    EXPECT_EQ(1, rect.x);
    EXPECT_EQ(2, rect.y);
    EXPECT_EQ(3, rect.w);
    EXPECT_EQ(4, rect.h);
  }

  TEST(RectangleTest, ToString) {
    EXPECT_EQ("Rectangle(1, 2, 3, 4)", Rectangle(1, 2, 3, 4).toString());
  }

  TEST(RectangleTest, ScaleOrigin) {
    Rectangle r(1, 2, 3, 4);

    EXPECT_EQ(Rectangle(0, 0, 3, 4), r.scaleOrigin(Vector2(0, 0)));
    EXPECT_EQ(Rectangle(4, 8, 3, 4), r.scaleOrigin(Vector2(4, 4)));
  }

  TEST(RectangleTest, X) {
    Rectangle r(1, 2, 3, 4);

    EXPECT_EQ(1, r.x());
  }

  TEST(RectangleTest, Y) {
    Rectangle r(1, 2, 3, 4);

    EXPECT_EQ(2, r.y());
  }

  TEST(RectangleTest, Width) {
    Rectangle r(1, 2, 3, 4);

    EXPECT_EQ(3, r.width());
  }

  TEST(RectangleTest, Height) {
    Rectangle r(1, 2, 3, 4);

    EXPECT_EQ(4, r.height());
  }
}

#include "gtest/gtest.h"
#include "point.cpp"

namespace green_leaf {
  class PointTest : public ::testing::Test {
  protected:
    PointTest() :
      point_(Point(1, 2))
    {
    }

    const Point point_;
  };

  TEST_F(PointTest, DefaultConstructor) {
    EXPECT_EQ(1, point_.x());
    EXPECT_EQ(2, point_.y());
  }

  TEST_F(PointTest, Identity) {
    EXPECT_EQ(point_, point_);
  }

  TEST_F(PointTest, Equality) {
    EXPECT_EQ(Point(1, 2), point_);
  }

  TEST_F(PointTest, Inequality) {
    EXPECT_NE(Point(1, 1), point_);
  }
}

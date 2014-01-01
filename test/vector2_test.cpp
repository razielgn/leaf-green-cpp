#include "gtest/gtest.h"
#include <string>
#include "vector2.hpp"

namespace green_leaf {
  class Vector2Test : public ::testing::Test {
  protected:
    Vector2Test() :
      vec_(Vector2(1, 2))
    {
    }

    const Vector2 vec_;
  };

  TEST_F(Vector2Test, DefaultConstructor) {
    EXPECT_EQ(1, vec_.x());
    EXPECT_EQ(2, vec_.y());
  }

  TEST_F(Vector2Test, Identity) {
    EXPECT_EQ(vec_, vec_);
  }

  TEST_F(Vector2Test, Equality) {
    EXPECT_EQ(Vector2(1, 2), vec_);
  }

  TEST_F(Vector2Test, Inequality) {
    EXPECT_NE(Vector2(1, 1), vec_);
  }

  TEST_F(Vector2Test, Assignment) {
    Vector2 point(1, 2);
    point = Vector2(3, 4);

    EXPECT_EQ(3, point.x());
    EXPECT_EQ(4, point.y());
  }

  TEST_F(Vector2Test, ToString) {
    ASSERT_EQ(std::string("Vector2(1, 2)"), vec_.toString());
  }

  TEST_F(Vector2Test, Sum) {
    EXPECT_EQ(Vector2(2, 5), Vector2(0, 0) + Vector2(2, 5));
    EXPECT_EQ(Vector2(2, 5), Vector2(1, 2) + Vector2(1, 3));
  }

  TEST_F(Vector2Test, Difference) {
    EXPECT_EQ(Vector2(-2, -5), Vector2(0, 0) - Vector2(2, 5));
    EXPECT_EQ(Vector2(-0, -1), Vector2(1, 2) - Vector2(1, 3));
  }

  TEST_F(Vector2Test, Multiplication) {
    EXPECT_EQ(Vector2(0, 0), Vector2(0, 0) * 0.0f);
    EXPECT_EQ(Vector2(0, 0), Vector2(1, 4) * 0.0f);
    EXPECT_EQ(Vector2(4, -8), Vector2(2, -4) * 2.0f);
  }

  TEST_F(Vector2Test, MultiplicationByVector2) {
    EXPECT_EQ(Vector2(0, 0), Vector2(0, 0) * Vector2(1, 2));
    EXPECT_EQ(Vector2(3, 20), Vector2(1, 4) * Vector2(3, 5));
  }

  TEST_F(Vector2Test, DivisionByVector2) {
    EXPECT_EQ(Vector2(0, 0), Vector2(0, 0) / Vector2(1, 1));
    EXPECT_EQ(Vector2(2, 2), Vector2(20, 10) / Vector2(10, 5));
  }
}

#include "vector2f.hpp"

#include "gtest/gtest.h"
#include "vector2.hpp"
#include <string>

namespace green_leaf {
  class Vector2fTest : public ::testing::Test {
  protected:
    Vector2fTest() :
      vec_(Vector2f(1.0f, 2.0f))
    {
    }

    Vector2f vec_;
  };

  TEST_F(Vector2fTest, DefaultConstructor) {
    EXPECT_FLOAT_EQ(1.0f, vec_.x());
    EXPECT_FLOAT_EQ(2.0f, vec_.y());
  }

  TEST_F(Vector2fTest, ConstructorWithVector2) {
    Vector2f vector(Vector2(2, 5));

    EXPECT_FLOAT_EQ(2.0f, vector.x());
    EXPECT_FLOAT_EQ(5.0f, vector.y());
  }

  TEST_F(Vector2fTest, Identity) {
    EXPECT_EQ(vec_, vec_);
  }

  TEST_F(Vector2fTest, Equality) {
    EXPECT_EQ(Vector2f(1.0f, 2.0f), vec_);
  }

  TEST_F(Vector2fTest, Inequality) {
    EXPECT_NE(Vector2f(1.0f, 1.0f), vec_);
  }

  TEST_F(Vector2fTest, Assignment) {
    vec_ = Vector2f(3.0f, 4.0f);

    EXPECT_FLOAT_EQ(3.0f, vec_.x());
    EXPECT_FLOAT_EQ(4.0f, vec_.y());
  }

  TEST_F(Vector2fTest, ToString) {
    EXPECT_EQ(std::string("Vector2f(1.5, 2.5)"), Vector2f(1.5f, 2.5f).toString());
  }

  TEST_F(Vector2fTest, ToVector2) {
    Vector2 vector = vec_.toVector2();

    EXPECT_EQ(1, vector.x());
    EXPECT_EQ(2, vector.y());
  }

  TEST_F(Vector2fTest, Sum) {
    EXPECT_EQ(Vector2f(2.0f, 5.0f), Vector2f(0.0f, 0.0f) + Vector2f(2.0f, 5.0f));
    EXPECT_EQ(Vector2f(2.0f, 5.0f), Vector2f(1.0f, 2.0f) + Vector2f(1.0f, 3.0f));
  }

  TEST_F(Vector2fTest, Diference) {
    EXPECT_EQ(Vector2f(-2.0f, -5.0f), Vector2f(0.0f, 0.0f) - Vector2f(2.0f, 5.0f));
    EXPECT_EQ(Vector2f(-0.0f, -1.0f), Vector2f(1.0f, 2.0f) - Vector2f(1.0f, 3.0f));
  }

  TEST_F(Vector2fTest, Multiplication) {
    EXPECT_EQ(Vector2f( 0.0f, 0.0f), Vector2f(0.0f, 0.0f) * 0.0f);
    EXPECT_EQ(Vector2f( 0.0f, 0.0f), Vector2f(1.0f, 4.0f) * 0.0f);
    EXPECT_EQ(Vector2f(4.0f, -8.0f), Vector2f(2.0f, -4.0f) * 2.0f);
  }

  TEST_F(Vector2fTest, Division) {
    EXPECT_EQ(Vector2f( 0.0f, 0.0f), Vector2f( 0.0f,  0.0f) / 1.0f);
    EXPECT_EQ(Vector2f(10.0f, 5.0f), Vector2f(20.0f, 10.0f) / 2.0f);
  }

  TEST_F(Vector2fTest, MultiplicationByVector2f) {
    EXPECT_EQ(Vector2f( 0.0f, 0.0f), Vector2f(0.0f, 0.0f) * Vector2f(1.0f, 2.0f));
    EXPECT_EQ(Vector2f(3.0f, 20.0f), Vector2f(1.0f, 4.0f) * Vector2f(3.0f, 5.0f));
  }

  TEST_F(Vector2fTest, DivisionByVector2f) {
    EXPECT_EQ(Vector2f(0.0f, 0.0f), Vector2f( 0.0f,  0.0f) / Vector2f( 1.0f, 1.0f));
    EXPECT_EQ(Vector2f(2.0f, 2.0f), Vector2f(20.0f, 10.0f) / Vector2f(10.0f, 5.0f));
  }
}

#include "menu_triangle_state.hpp"

#include "gtest/gtest.h"

namespace green_leaf {
  using namespace ::testing;

  class MenuTriangleStateTest : public Test {
  protected:
    MenuTriangleState mts_;
  };

  TEST_F(MenuTriangleStateTest, Offset) {
    EXPECT_EQ(0u, mts_.offset());
  }

  TEST_F(MenuTriangleStateTest, Update) {
    const unsigned int elapsed = 150u;

    mts_.update(GameTime(elapsed, 0));
    EXPECT_EQ(1u, mts_.offset());

    mts_.update(GameTime(elapsed, 0));
    EXPECT_EQ(2u, mts_.offset());

    mts_.update(GameTime(elapsed, 0));
    EXPECT_EQ(1u, mts_.offset());

    mts_.update(GameTime(elapsed, 0));
    EXPECT_EQ(0u, mts_.offset());

    mts_.update(GameTime(elapsed, 0));
    EXPECT_EQ(1u, mts_.offset());
  }
}

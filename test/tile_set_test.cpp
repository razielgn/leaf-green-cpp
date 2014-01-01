#include "gtest/gtest.h"

#include "vector2.hpp"
#include "texture.hpp"
#include "tile_set.hpp"

namespace green_leaf {
  class TileSetTest : public ::testing::Test {
  protected:
    TileSetTest() {
      texture_ = new Texture(Vector2(48, 48));
      tile_set_ = new TileSet(texture_, tile_size_, 1);
    }
    ~TileSetTest() {
      delete texture_;
      delete tile_set_;
    }

    const TileSet* tile_set_;
    Texture* texture_;
    const Vector2 tile_size_ = Vector2(16, 16);
  };

  TEST_F(TileSetTest, Texture) {
    EXPECT_EQ(texture_, tile_set_->texture());
  }

  TEST_F(TileSetTest, TileSize) {
    EXPECT_EQ(tile_size_, tile_set_->tile_size());
  }

  TEST_F(TileSetTest, RectangleFromCode) {
    EXPECT_EQ(Rectangle(0, 0, 16, 16), tile_set_->rectangleFromCode(1));
    EXPECT_EQ(Rectangle(1, 0, 16, 16), tile_set_->rectangleFromCode(2));
    EXPECT_EQ(Rectangle(2, 0, 16, 16), tile_set_->rectangleFromCode(3));
    EXPECT_EQ(Rectangle(0, 1, 16, 16), tile_set_->rectangleFromCode(4));
    EXPECT_EQ(Rectangle(1, 1, 16, 16), tile_set_->rectangleFromCode(5));
    EXPECT_EQ(Rectangle(2, 1, 16, 16), tile_set_->rectangleFromCode(6));
    EXPECT_EQ(Rectangle(0, 2, 16, 16), tile_set_->rectangleFromCode(7));
    EXPECT_EQ(Rectangle(1, 2, 16, 16), tile_set_->rectangleFromCode(8));
    EXPECT_EQ(Rectangle(2, 2, 16, 16), tile_set_->rectangleFromCode(9));
  }
}

#include "gmock/gmock.h"

#include "graphics_mock.hpp"
#include "texture_mock.hpp"
#include "tile_layer.hpp"
#include "tile_set.hpp"
#include "vector2.hpp"

namespace green_leaf {
  using namespace ::testing;

  class TileLayerTest : public Test {
  protected:
    TileLayerTest() { }

    TextureMock texture_ = TextureMock(Vector2(12, 12));
    Vector2 tile_size_ = Vector2(4, 4);
    TileSet tile_set_ = TileSet(&texture_, tile_size_, 1);

    StrictMock<GraphicsMock> graphics_;
  };

  TEST_F(TileLayerTest, TileSet) {
    std::vector<unsigned int> tiles;
    TileLayer tile_layer = TileLayer(Vector2(3, 3), &tile_set_, tiles);

    EXPECT_EQ(&tile_set_, tile_layer.tile_set());
  }

  TEST_F(TileLayerTest, Tiles) {
    std::vector<unsigned int> tiles = { 1, 2, 3,
                                        4, 5, 6,
                                        7, 8, 9 };
    TileLayer tile_layer = TileLayer(Vector2(3, 3), &tile_set_, tiles);

    EXPECT_EQ(tiles, tile_layer.tiles());
  }

  TEST_F(TileLayerTest, DrawShouldNeverDrawWhenTilesAreAllEmpty) {
    EXPECT_CALL(graphics_, drawTexture(&texture_, _, _)).Times(0);

    std::vector<unsigned int> tiles = { 0, 0, 0,
                                        0, 0, 0,
                                        0, 0, 0 };
    TileLayer tile_layer = TileLayer(Vector2(3, 3), &tile_set_, tiles);

    tile_layer.draw(&graphics_, Vector2(0, 0));
  }

  TEST_F(TileLayerTest, DrawShouldDrawEveryTile) {
    EXPECT_CALL(graphics_, drawTexture(&texture_, _, _)).Times(9);

    std::vector<unsigned int> tiles = { 1, 2, 3,
                                        4, 5, 6,
                                        7, 8, 9 };
    TileLayer tile_layer = TileLayer(Vector2(3, 3), &tile_set_, tiles);

    tile_layer.draw(&graphics_, Vector2(0, 0));
  }

  TEST_F(TileLayerTest, DrawShouldCallDrawTextureWithCorrectParameters) {
    EXPECT_CALL(graphics_,
        drawTexture(&texture_, Rectangle( 5, 17, tile_size_), Rectangle(0, 0, tile_size_)));
    EXPECT_CALL(graphics_,
        drawTexture(&texture_, Rectangle( 9, 17, tile_size_), Rectangle(4, 0, tile_size_)));
    EXPECT_CALL(graphics_,
        drawTexture(&texture_, Rectangle(13, 17, tile_size_), Rectangle(8, 0, tile_size_)));
    EXPECT_CALL(graphics_,
        drawTexture(&texture_, Rectangle( 5, 21, tile_size_), Rectangle(0, 4, tile_size_)));
    EXPECT_CALL(graphics_,
        drawTexture(&texture_, Rectangle( 9, 21, tile_size_), Rectangle(4, 4, tile_size_)));
    EXPECT_CALL(graphics_,
        drawTexture(&texture_, Rectangle(13, 21, tile_size_), Rectangle(8, 4, tile_size_)));
    EXPECT_CALL(graphics_,
        drawTexture(&texture_, Rectangle( 5, 25, tile_size_), Rectangle(0, 8, tile_size_)));
    EXPECT_CALL(graphics_,
        drawTexture(&texture_, Rectangle( 9, 25, tile_size_), Rectangle(4, 8, tile_size_)));
    EXPECT_CALL(graphics_,
        drawTexture(&texture_, Rectangle(13, 25, tile_size_), Rectangle(8, 8, tile_size_)));

    std::vector<unsigned int> tiles = { 1, 2, 3,
                                        4, 5, 6,
                                        7, 8, 9 };
    TileLayer tile_layer = TileLayer(Vector2(3, 3), &tile_set_, tiles);

    tile_layer.draw(&graphics_, Vector2(5, 17));
  }
}

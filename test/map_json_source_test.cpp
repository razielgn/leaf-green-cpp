#include "gmock/gmock.h"
#include "collisions_layer.hpp"
#include "map_json_source.hpp"
#include "tile_layer.hpp"
#include "tile_set.hpp"
#include "content_mock.hpp"

namespace green_leaf {
  using namespace ::testing;

  class MapJsonSourceTest : public TestWithParam<const MapJsonSource*> {
  protected:
    MapJsonSourceTest() { }
  };

  TEST_P(MapJsonSourceTest, Resolution) {
    EXPECT_EQ(Vector2(64, 60), GetParam()->resolution());
  }

  TEST_P(MapJsonSourceTest, TileSize) {
    EXPECT_EQ(Vector2(16, 20), GetParam()->tileSize());
  }

  TEST_P(MapJsonSourceTest, BackgroundLayer) {
    const TileLayer& backgroundLayer = GetParam()->backgroundLayer();

    EXPECT_EQ(Vector2(4, 3), backgroundLayer.size());

    std::vector<unsigned int> tiles = { 1, 2, 3, 4 };
    EXPECT_EQ(tiles, backgroundLayer.tiles());

    const TileSet& tile_set = backgroundLayer.tileSet();
    EXPECT_EQ(GetParam()->tileSize(), tile_set.tileSize());
    EXPECT_EQ(1u, tile_set.startCode());
  }

  TEST_P(MapJsonSourceTest, FloorLayer) {
    const TileLayer& floorLayer = GetParam()->floorLayer();

    EXPECT_EQ(Vector2(4, 3), floorLayer.size());

    std::vector<unsigned int> tiles = { 5, 6, 7, 8 };
    EXPECT_EQ(tiles, floorLayer.tiles());

    const TileSet& tile_set = floorLayer.tileSet();
    EXPECT_EQ(GetParam()->tileSize(), tile_set.tileSize());
    EXPECT_EQ(5u, tile_set.startCode());
  }

  TEST_P(MapJsonSourceTest, DecorationsLayer) {
    const TileLayer& decorationsLayer = GetParam()->decorationsLayer();

    EXPECT_EQ(Vector2(4, 3), decorationsLayer.size());

    std::vector<unsigned int> tiles = { 9, 10, 11, 12 };
    EXPECT_EQ(tiles, decorationsLayer.tiles());

    const TileSet& tile_set = decorationsLayer.tileSet();
    EXPECT_EQ(GetParam()->tileSize(), tile_set.tileSize());
    EXPECT_EQ(5u, tile_set.startCode());
  }

  TEST_P(MapJsonSourceTest, ForegroundLayer) {
    const TileLayer& foregroundLayer = GetParam()->foregroundLayer();

    EXPECT_EQ(Vector2(4, 3), foregroundLayer.size());

    std::vector<unsigned int> tiles = { 13, 14, 15, 16 };
    EXPECT_EQ(tiles, foregroundLayer.tiles());

    const TileSet& tile_set = foregroundLayer.tileSet();
    EXPECT_EQ(GetParam()->tileSize(), tile_set.tileSize());
    EXPECT_EQ(5u, tile_set.startCode());
  }

  TEST_P(MapJsonSourceTest, CollisionsLayer) {
    const CollisionsLayer& collisions_layer = GetParam()->collisionsLayer();
    std::vector<Rectangle> rectangles = collisions_layer.rectangles();

    EXPECT_EQ(2u, rectangles.size());

    EXPECT_EQ(Rectangle(80, 64, 16, 32), rectangles[0]);
    EXPECT_EQ(Rectangle(0, 16, 32, 32),  rectangles[1]);
  }

  const ContentMock content_;
  const MapJsonSource map_source_1(content_, std::string("test_map.json"));
  const MapJsonSource map_source_2(content_, std::string("test_map_shuffled.json"));

  INSTANTIATE_TEST_CASE_P(
    MapJsonSourceTest1,
    MapJsonSourceTest,
    ::testing::Values(&map_source_1)
  );

  INSTANTIATE_TEST_CASE_P(
    MapJsonSourceTest2,
    MapJsonSourceTest,
    ::testing::Values(&map_source_2)
  );
}

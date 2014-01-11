#include "gmock/gmock.h"
#include "map_json_source.hpp"
#include "tile_layer.hpp"
#include "tile_set.hpp"
#include "content_mock.hpp"

namespace green_leaf {
  using namespace ::testing;

  class MapJsonSourceTest : public Test {
  protected:
    MapJsonSourceTest() { }

    const ContentMock content_;
    const std::string path = std::string("test_map.json");
    const MapJsonSource map_source_ = MapJsonSource(&content_, path);
  };

  TEST_F(MapJsonSourceTest, Resolution) {
    EXPECT_EQ(Vector2(64, 60), map_source_.resolution());
  }

  TEST_F(MapJsonSourceTest, TileSize) {
    EXPECT_EQ(Vector2(16, 20), map_source_.tile_size());
  }

  TEST_F(MapJsonSourceTest, BackgroundLayer) {
    TileLayer* backgroundLayer = map_source_.backgroundLayer();

    EXPECT_EQ(Vector2(4, 3), backgroundLayer->size());

    std::vector<unsigned int> tiles = { 1, 2, 3, 4 };
    EXPECT_EQ(tiles, backgroundLayer->tiles());

    const TileSet* tile_set = backgroundLayer->tile_set();
    EXPECT_EQ(map_source_.tile_size(), tile_set->tile_size());
    EXPECT_EQ(1, tile_set->start_code());
  }

  TEST_F(MapJsonSourceTest, FloorLayer) {
    TileLayer* floorLayer = map_source_.floorLayer();

    EXPECT_EQ(Vector2(4, 3), floorLayer->size());

    std::vector<unsigned int> tiles = { 5, 6, 7, 8 };
    EXPECT_EQ(tiles, floorLayer->tiles());

    const TileSet* tile_set = floorLayer->tile_set();
    EXPECT_EQ(map_source_.tile_size(), tile_set->tile_size());
    EXPECT_EQ(5, tile_set->start_code());
  }

  TEST_F(MapJsonSourceTest, DecorationsLayer) {
    TileLayer* decorationsLayer = map_source_.decorationsLayer();

    EXPECT_EQ(Vector2(4, 3), decorationsLayer->size());

    std::vector<unsigned int> tiles = { 9, 10, 11, 12 };
    EXPECT_EQ(tiles, decorationsLayer->tiles());

    const TileSet* tile_set = decorationsLayer->tile_set();
    EXPECT_EQ(map_source_.tile_size(), tile_set->tile_size());
    EXPECT_EQ(5, tile_set->start_code());
  }

  TEST_F(MapJsonSourceTest, ForegroundLayer) {
    TileLayer* foregroundLayer = map_source_.foregroundLayer();

    EXPECT_EQ(Vector2(4, 3), foregroundLayer->size());

    std::vector<unsigned int> tiles = { 13, 14, 15, 16 };
    EXPECT_EQ(tiles, foregroundLayer->tiles());

    const TileSet* tile_set = foregroundLayer->tile_set();
    EXPECT_EQ(map_source_.tile_size(), tile_set->tile_size());
    EXPECT_EQ(5, tile_set->start_code());
  }
}

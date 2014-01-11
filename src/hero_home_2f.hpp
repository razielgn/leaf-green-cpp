#ifndef GL_HERO_HOME_2F_HPP
#define GL_HERO_HOME_2F_HPP

#include "map_source.hpp"
#include "tile_set.hpp"
#include "tile_layer.hpp"
#include "content.hpp"
#include <vector>

namespace green_leaf {
  class HeroHome2F : public MapSource {
  public:
    HeroHome2F(const Content* content)
      : content_(content)
      , dimension_(Vector2(11, 9))
      , tile_size_(Vector2(16, 16))
    {
      background_texture_  = content_->loadTexture("background.png");
      decorations_texture_ = content_->loadTexture("decorations.png");

      background_tile_set_  = new TileSet(background_texture_, tile_size_, 1);
      decorations_tile_set_ = new TileSet(decorations_texture_, tile_size_, 401);

      std::vector<unsigned int> background_tiles = { 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 23, 3, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
      background_tile_layer_ = new TileLayer(dimension_, background_tile_set_, background_tiles);

      std::vector<unsigned int> floor_tiles = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 432, 433, 444, 445, 445, 445, 446, 0, 0, 0, 441, 442, 443, 454, 455, 455, 455, 456, 0, 0, 0, 0, 0, 0, 454, 455, 455, 455, 456, 0, 0, 0, 0, 0, 0, 464, 465, 465, 465, 466, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
      floor_tile_layer_ = new TileLayer(dimension_, decorations_tile_set_, floor_tiles);

      std::vector<unsigned int> object_tiles = { 401, 402, 403, 404, 405, 0, 0, 0, 0, 0, 409, 411, 412, 413, 414, 415, 0, 0, 407, 408, 0, 419, 421, 422, 423, 424, 425, 0, 0, 417, 418, 410, 0, 0, 0, 0, 0, 0, 0, 0, 427, 428, 420, 0, 0, 0, 0, 0, 0, 416, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 426, 0, 0, 0, 0, 0, 451, 452, 453, 0, 0, 436, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
      decorations_tile_layer_ = new TileLayer(dimension_, decorations_tile_set_, object_tiles);

      std::vector<unsigned int> foreground_tiles = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 406, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 461, 462, 463, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
      foreground_tile_layer_ = new TileLayer(dimension_, decorations_tile_set_, foreground_tiles);
    }

    ~HeroHome2F() {
    }

    TileLayer* backgroundLayer() const {
      return background_tile_layer_;
    }

    TileLayer* decorationsLayer() const {
      return decorations_tile_layer_;
    }

    TileLayer* floorLayer() const {
      return floor_tile_layer_;
    }

    TileLayer* foregroundLayer() const {
      return foreground_tile_layer_;
    }

    Vector2 resolution() const {
      return dimension_ * tile_size_;
    }

    Vector2 tile_size() const {
      return tile_size_;
    }

  private:
    const Content* content_;

    Texture* background_texture_;
    Texture* decorations_texture_;

    TileSet* background_tile_set_;
    TileSet* decorations_tile_set_;

    TileLayer* background_tile_layer_;
    TileLayer* floor_tile_layer_;
    TileLayer* decorations_tile_layer_;
    TileLayer* foreground_tile_layer_;

    Vector2 dimension_;
    Vector2 tile_size_;
  };
}

#endif

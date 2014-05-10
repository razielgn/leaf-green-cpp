#ifndef GL_CONTENT_HPP
#define GL_CONTENT_HPP

#include <string>

#include <memory>

namespace green_leaf {
  class BitmapFont;
  class MapSource;
  class Texture;

  class Content {
  public:
    virtual ~Content() { }

    virtual std::unique_ptr<const Texture> loadTexture(const std::string path) const = 0;
    virtual std::unique_ptr<const MapSource> loadMap(const std::string map_name) const = 0;
    virtual std::unique_ptr<const BitmapFont> loadBitmapFont(const std::string path) const = 0;
  };
}

#endif

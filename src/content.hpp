#ifndef GL_CONTENT_HPP
#define GL_CONTENT_HPP

#include <string>

namespace green_leaf {
  class MapSource;
  class Texture;

  class Content {
  public:
    virtual ~Content() { }

    virtual const Texture* loadTexture(std::string path) const = 0;
    virtual const MapSource* loadMap(std::string map_name) const = 0;
  };
}

#endif

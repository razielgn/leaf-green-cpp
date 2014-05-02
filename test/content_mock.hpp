#ifndef GL_CONTENT_MOCK_HPP
#define GL_CONTENT_MOCK_HPP

#include "content.hpp"
#include "map_source.hpp"
#include "texture_mock.hpp"
#include "unused.hpp"

namespace green_leaf {
  class ContentMock : public Content {
  public:
    ContentMock() { }

    std::unique_ptr<const Texture> loadTexture(const std::string path) const {
      UNUSED(path);

      return std::make_unique<const TextureMock>(Vector2(0, 0));
    }

    std::unique_ptr<const MapSource> loadMap(const std::string map_name) const {
      UNUSED(map_name);

      return std::unique_ptr<const MapSource>(nullptr);
    }
  };
}

#endif

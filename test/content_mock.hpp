#ifndef GL_CONTENT_MOCK_HPP
#define GL_CONTENT_MOCK_HPP

#include "content.hpp"
#include "texture_mock.hpp"
#include "unused.hpp"

namespace green_leaf {
  class ContentMock : public Content {
  public:
    ContentMock() { }

    const Texture* loadTexture(std::string path) const {
      UNUSED(path);

      return new TextureMock(Vector2(0, 0));
    }

    MOCK_CONST_METHOD1(loadMap, const MapSource*(std::string map_name));
  };
}

#endif

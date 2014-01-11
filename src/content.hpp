#ifndef GL_CONTENT_HPP
#define GL_CONTENT_HPP

#include <string>

namespace green_leaf {
  class Texture;

  class Content {
  public:
    virtual ~Content() { }

    virtual Texture* loadTexture(std::string path) const = 0;
  };
}

#endif

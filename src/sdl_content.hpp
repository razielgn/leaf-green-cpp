#ifndef GL_SDL_CONTENT_HPP
#define GL_SDL_CONTENT_HPP

#include "content.hpp"

namespace green_leaf {
  class Graphics;
  class Texture;

  class SDLContent : public Content {
  public:
    SDLContent(Graphics* graphics_, std::string base_path);

    Texture* loadTexture(std::string path) const;

  private:
    Graphics* graphics_;
    std::string base_path_;

    std::string fullPath(std::string path) const;
  };
}

#endif

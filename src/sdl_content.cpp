#include "sdl_content.hpp"
#include "sdl_texture.hpp"

namespace green_leaf {
  SDLContent::SDLContent(Graphics* graphics, std::string base_path)
    : graphics_(graphics)
    , base_path_(base_path)
  {
  }

  std::string SDLContent::fullPath(std::string path) const {
    return base_path_ + std::string("/") + path;
  }

  Texture* SDLContent::loadTexture(std::string path) const {
    return SDLTexture::fromPath(graphics_, fullPath(path));
  }
}

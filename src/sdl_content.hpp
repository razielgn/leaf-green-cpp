#ifndef GL_SDL_CONTENT_HPP
#define GL_SDL_CONTENT_HPP

#include "content.hpp"

namespace green_leaf {
  class Graphics;

  class SDLContent : public Content {
  public:
    SDLContent(const Graphics& graphics_, const std::string base_path);

    std::unique_ptr<const Texture> loadTexture(const std::string path) const;
    std::unique_ptr<const MapSource> loadMap(const std::string path) const;

  private:
    const Graphics& graphics_;
    const std::string base_path_;

#if defined(WIN32) || defined(_WIN32)
    const std::string dir_sep_ = "\\";
#else
    const std::string dir_sep_ = "/";
#endif

    const std::string maps_ext_ = ".json";

    std::string fullPath(std::string path) const;
  };
}

#endif

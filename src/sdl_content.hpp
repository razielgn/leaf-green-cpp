#ifndef GL_SDL_CONTENT_HPP
#define GL_SDL_CONTENT_HPP

#include "content.hpp"

namespace green_leaf {
  class Graphics;

  class SDLContent : public Content {
  public:
    SDLContent(const Graphics* graphics_, const std::string base_path);

    const Texture* loadTexture(const std::string path) const;
    const MapSource* loadMap(const std::string path) const;

  private:
    const Graphics* graphics_;
    const std::string base_path_;

#if defined(WIN32) || defined(_WIN32)
    const std::string dir_sep_ = std::string("\\");
#else
    const std::string dir_sep_ = std::string("/");
#endif

    const std::string maps_folder_ = std::string("maps");
    const std::string maps_ext_ = std::string(".json");

    std::string fullPath(std::string path) const;
    std::string fullPath(std::string folders, std::string path) const;
  };
}

#endif

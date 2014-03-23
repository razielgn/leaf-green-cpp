#ifndef GL_UTILS_STRING_HPP
#define GL_UTILS_STRING_HPP

#include <string>
#include <vector>

namespace green_leaf {
  namespace utils {
    std::vector<std::string> split(const std::string string, const std::string token);
  }
}

#endif

#pragma once

#include <string>
#include <vector>

namespace green_leaf {
  namespace utils {
    std::vector<std::string> split(const std::string string, const std::string token);
    size_t utf8Length(const std::string string);
  }
}

#include "string.hpp"

namespace green_leaf {
  namespace utils {
    std::vector<std::string> split(const std::string string, const std::string token) {
      std::vector<std::string> tokens;
      size_t index = 0, match = 0;

      do {
        match = string.find(token, index);
        tokens.push_back(string.substr(index, match - index));
        index = match + token.length();
      } while(match != std::string::npos);

      return tokens;
    }
  }
}

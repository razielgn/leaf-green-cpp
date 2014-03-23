#include "gtest/gtest.h"

#include "utils/string.hpp"

namespace green_leaf {
  namespace utils {
    TEST(StringUtils, SplitNoMatch) {
      const std::string str = "abc";
      std::vector<std::string> expected { str };
      EXPECT_EQ(expected, split(str, ","));
    }

    TEST(StringUtils, SplitOneCharToken) {
      const std::string str = "a,c";
      std::vector<std::string> expected { "a", "c" };
      EXPECT_EQ(expected, split(str, ","));
    }

    TEST(StringUtils, SplitTwoCharsToken) {
      const std::string str = "a,.c";
      std::vector<std::string> expected { "a", "c" };
      EXPECT_EQ(expected, split(str, ",."));
    }

    TEST(StringUtils, SplitMultiple) {
      const std::string str = "a,.cacca,.d,.abba";
      std::vector<std::string> expected { "a", "cacca", "d", "abba" };
      EXPECT_EQ(expected, split(str, ",."));
    }
  }
}

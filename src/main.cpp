#include <iostream>
#include <memory>
#include <string>

#include "game.hpp"

int main() {
  try {
    auto game = std::make_unique<green_leaf::Game>();

    game->loadContent();
    game->run();
  } catch(const char* message) {
    std::cout << message << std::endl;
  }

  return 0;
}

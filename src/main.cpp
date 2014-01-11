#include <string>
#include <iostream>

#include "game.hpp"

int main() {
  try {
    green_leaf::Game *game = new green_leaf::Game();

    game->loadContent();
    game->run();

    game->unloadContent();

    delete game;
  } catch(const char* message) {
    std::cout << message << std::endl;
  }

  return 0;
}

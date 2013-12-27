#include "game.hpp"

int main() {
  using namespace green_leaf;

  Game *game = new Game();

  game->loadContent();
  game->run();

  game->unloadContent();

  delete game;
  return 0;
}

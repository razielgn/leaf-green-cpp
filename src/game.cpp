#include "game.hpp"
#include "game_time.hpp"
#include "graphics.hpp"
#include "sdl_input.hpp"
#include "map.hpp"
#include "vector2.hpp"
#include "player.hpp"
#include "player_movement.hpp"

namespace green_leaf {
  Game::Game() {
    graphics_ = new Graphics();
    input_ = new SDLInput();
    player_ = new Player();
    map_ = new Map(Vector2(5, 6));
    player_movement_ = new PlayerMovement();

    running_ = true;
    total_time_ = SDL_GetTicks();
  }

  Game::~Game() {
    delete graphics_;
    delete input_;
    delete player_;
    delete player_movement_;
    delete map_;
  }

  void Game::loadContent() {
    player_->loadContent(graphics_);
    map_->loadContent(graphics_);
  }

  void Game::unloadContent() {
    player_->unloadContent();
    map_->unloadContent();
  }

  void Game::run() {
    while(running_) {
      int delay_time = 1000.0f / 60;
      int frame_start = SDL_GetTicks();

      update();
      draw();

      int frame_time = SDL_GetTicks() - frame_start;

      if(frame_time < delay_time) {
        SDL_Delay((int)(delay_time - frame_time));
      }
    }
  }

  void Game::update() {
    unsigned int now = SDL_GetTicks();
    GameTime game_time(now - total_time_, now);

    input_->recordState();

    if(input_->hasQuit()) {
      stop();
    }

    player_movement_->update(input_, &game_time);
    player_->update(input_, &game_time, player_movement_);
    map_->update(input_, &game_time, player_movement_);

    total_time_ = SDL_GetTicks();
  }

  void Game::draw() {
    graphics_->clear();

    map_->draw(graphics_);
    player_->draw(graphics_);

    graphics_->present();
  }

  void Game::stop() {
    running_ = false;
  }
}

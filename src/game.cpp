#include "game.hpp"
#include "graphics.hpp"
#include "input.hpp"
#include "player.hpp"

namespace green_leaf {
  Game::Game() {
    graphics_ = new Graphics();
    input_ = new Input();
    player_ = new Player();

    running_ = true;
  }

  Game::~Game() {
    delete graphics_;
    delete input_;
    delete player_;
  }

  void Game::loadContent() {
    player_->loadContent(graphics_);
  }

  void Game::unloadContent() {
    player_->unloadContent();
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
    input_->recordState();

    if(input_->hasQuit()) {
      stop();
    }

    player_->update(input_);
  }

  void Game::draw() {
    graphics_->clear();

    player_->draw(graphics_);

    graphics_->present();
  }

  void Game::stop() {
    running_ = false;
  }
}

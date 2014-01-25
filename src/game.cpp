#include "game.hpp"
#include "game_time.hpp"
#include "sdl_graphics.hpp"
#include "sdl_input.hpp"
#include "sdl_content.hpp"
#include "map_screen.hpp"
#include "vector2.hpp"

namespace green_leaf {
  Game::Game() {
    graphics_ = new SDLGraphics();
    input_ = new SDLInput();
    content_ = new SDLContent(graphics_, std::string("./assets"));

    running_ = true;
    total_time_ = SDL_GetTicks();

    screens_.push_back(new MapScreen(std::string("hero_home_2f"), Vector2(5, 6), graphics_->size()));
  }

  Game::~Game() {
    delete graphics_;
    delete input_;
    delete content_;

    for(Screen* screen : screens_) {
      delete screen;
    }
  }

  void Game::loadContent() {
    for(Screen* screen : screens_) {
      screen->loadContent(content_);
    }
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

    screens_.back()->update(input_, &game_time);

    total_time_ = SDL_GetTicks();
  }

  void Game::draw() const {
    graphics_->clear();

    for(Screen* screen : screens_) {
      screen->draw(graphics_);
    }

    graphics_->present();
  }

  void Game::stop() {
    running_ = false;
  }
}

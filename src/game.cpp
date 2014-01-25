#include "game.hpp"
#include "game_time.hpp"
#include "sdl_graphics.hpp"
#include "sdl_input.hpp"
#include "sdl_content.hpp"
#include "map_json_source.hpp"
#include "map_screen.hpp"
#include "vector2.hpp"

namespace green_leaf {
  Game::Game() {
    graphics_ = new SDLGraphics();
    input_ = new SDLInput();
    content_ = new SDLContent(graphics_, std::string("."));
    map_screen_ = new MapScreen(new MapJsonSource(content_, "src/hero_home_2f.json"), Vector2(5, 6), graphics_->size());

    running_ = true;
    total_time_ = SDL_GetTicks();
  }

  Game::~Game() {
    delete graphics_;
    delete input_;
    delete content_;
  }

  void Game::loadContent() {
    map_screen_->loadContent(content_);
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

    map_screen_->update(input_, &game_time);

    total_time_ = SDL_GetTicks();
  }

  void Game::draw() const {
    graphics_->clear();

    map_screen_->draw(graphics_);

    graphics_->present();
  }

  void Game::stop() {
    running_ = false;
  }
}

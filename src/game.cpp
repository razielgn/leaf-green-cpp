#include "game.hpp"

#include "game_time.hpp"
#include "map_screen.hpp"
#include "screen_manager.hpp"
#include "sdl_content.hpp"
#include "sdl_graphics.hpp"
#include "sdl_input.hpp"
#include "vector2.hpp"

namespace green_leaf {
  Game::Game() {
    graphics_ = new SDLGraphics();
    input_ = new SDLInput();
    content_ = new SDLContent(graphics_, std::string("./assets"));
    screen_manager_ = new ScreenManager();

    running_ = true;
    total_time_ = SDL_GetTicks();
  }

  Game::~Game() {
    delete graphics_;
    delete hero_home_2f_;
    delete input_;
    delete content_;
    delete screen_manager_;
  }

  void Game::loadContent() {
    std::unique_ptr<MapScreen> hero_home_2f_(
      new MapScreen(std::string("hero_home_2f"), Vector2(5, 6), graphics_->size())
    );
    hero_home_2f_->loadContent(content_);

    screen_manager_->push(std::move(hero_home_2f_));
  }

  void Game::run() {
    while(running_) {
      unsigned int delay_time = 1000 / 60;
      unsigned int frame_start = SDL_GetTicks();

      update();
      draw();

      unsigned int frame_time = SDL_GetTicks() - frame_start;

      if(frame_time < delay_time) {
        SDL_Delay((unsigned int)(delay_time - frame_time));
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

    screen_manager_->update(*input_, game_time);

    total_time_ = SDL_GetTicks();
  }

  void Game::draw() const {
    graphics_->clear();

    screen_manager_->draw(*graphics_);

    graphics_->present();
  }

  void Game::stop() {
    running_ = false;
  }
}

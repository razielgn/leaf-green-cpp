#include "game.hpp"

#include "game_time.hpp"
#include "map_screen.hpp"
#include "player_keyboard_input.hpp"
#include "sdl_content.hpp"
#include "sdl_graphics.hpp"
#include "sdl_keyboard_input.hpp"
#include "vector2.hpp"

namespace green_leaf {
  Game::Game()
    : graphics_(std::make_unique<SDLGraphics>(4))
    , input_(std::make_unique<PlayerKeyboardInput>(std::make_unique<SDLKeyboardInput>()))
    , content_(std::make_unique<SDLContent>(*graphics_, "./assets"))
    , screen_manager_(ScreenManager(*content_))
    , total_time_(SDL_GetTicks())
    , running_(true)
  {
  }

  void Game::loadContent() {
    std::unique_ptr<MapScreen> hero_home_2f(
      new MapScreen(screen_manager_, "hero_home_2f", Vector2(5, 6), Direction::Down, graphics_->size())
    );

    screen_manager_.push(std::move(hero_home_2f));
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

    input_->update();

    if(input_->escape()) {
      stop();
    }

    screen_manager_.update(*input_, game_time);

    total_time_ = SDL_GetTicks();
  }

  void Game::draw() const {
    graphics_->clear();

    screen_manager_.draw(*graphics_);

    graphics_->present();
  }

  void Game::stop() {
    running_ = false;
  }
}

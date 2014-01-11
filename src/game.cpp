#include "game.hpp"
#include "game_time.hpp"
#include "sdl_graphics.hpp"
#include "sdl_input.hpp"
#include "sdl_content.hpp"
#include "map.hpp"
#include "map_json_source.hpp"
#include "vector2.hpp"
#include "player.hpp"
#include "player_movement.hpp"

namespace green_leaf {
  Game::Game() {
    graphics_ = new SDLGraphics();
    input_ = new SDLInput();
    player_ = new Player();
    player_movement_ = new PlayerMovement();
    content_ = new SDLContent(graphics_, std::string("."));
    map_ = new Map(new MapJsonSource(content_, "src/hero_home_2f.json"), Vector2(5, 6));

    running_ = true;
    total_time_ = SDL_GetTicks();
  }

  Game::~Game() {
    delete graphics_;
    delete input_;
    delete player_;
    delete player_movement_;
    delete map_;
    delete content_;
  }

  void Game::loadContent() {
    player_->loadContent(content_);
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
    unsigned int now = SDL_GetTicks();
    GameTime game_time(now - total_time_, now);

    input_->recordState();

    if(input_->hasQuit()) {
      stop();
    }

    player_movement_->update(input_, &game_time);
    player_->update(player_movement_);
    map_->update(player_movement_);

    total_time_ = SDL_GetTicks();
  }

  void Game::draw() const {
    graphics_->clear();

    map_->drawBackground(graphics_);
    player_->draw(graphics_);
    map_->drawForeground(graphics_);

    graphics_->present();
  }

  void Game::stop() {
    running_ = false;
  }
}

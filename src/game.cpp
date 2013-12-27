#include "game.hpp"
#include "texture.hpp"

namespace green_leaf {
  Game::Game() {
    graphics_ = new Graphics();
  }

  Game::~Game() {
    delete graphics_;
  }

  void Game::loadContent() {
    hero_texture_ = Texture::from_path(graphics_, "hero.png");
  }

  void Game::unloadContent() {
    delete hero_texture_;
  }

  void Game::run() {
    running_ = true;
    update();
  }

  void Game::update() {
    SDL_Rect source_rect, dest_rect;
    int scale = 4;

    int frame = 0;
    int frame_w = 16;
    int frame_h = 20;

    int direction = 0;

    int fps = 60;
    int delay_time = 1000.0f / fps;
    int frame_start, frame_time;
    SDL_Event event;
    const Uint8 *key_state;

    bool walking = false;
      dest_rect.x = 200;
      dest_rect.y = 200;

    while(running_) {
      frame_start = SDL_GetTicks();

      key_state = SDL_GetKeyboardState(NULL);

      if(SDL_PollEvent(&event)) {
        switch(event.type) {
          case SDL_QUIT:
            stop();
            break;
          case SDL_KEYDOWN:
            if(key_state[SDL_SCANCODE_ESCAPE]) {
              stop();
            } else if(key_state[SDL_SCANCODE_RIGHT]) {
              direction = 3;
              walking = true;
            } else if(key_state[SDL_SCANCODE_LEFT]) {
              direction = 1;
              walking = true;
            } else if(key_state[SDL_SCANCODE_UP]) {
              direction = 2;
              walking = true;
            } else if(key_state[SDL_SCANCODE_DOWN]) {
              direction = 0;
              walking = true;
            }

            break;
          case SDL_KEYUP:
            if(!key_state[SDL_SCANCODE_RIGHT]) {
              walking = false;
            } else if(!key_state[SDL_SCANCODE_LEFT]) {
              walking = false;
            } else if(!key_state[SDL_SCANCODE_UP]) {
              walking = false;
            } else if(!key_state[SDL_SCANCODE_DOWN]) {
              walking = false;
            }

            break;
          default:
            break;
        }
      }

      source_rect.w = frame_w;
      source_rect.h = frame_h;
      if(walking) {
        source_rect.x = frame_w * int(((SDL_GetTicks() / 200) % 4));
      } else {
        source_rect.x = 0;
      }
      source_rect.y = frame_h * direction;

      dest_rect.w = source_rect.w * scale;
      dest_rect.h = source_rect.h * scale;

      graphics_->clear();
      graphics_->drawTexture(hero_texture_, &source_rect, &dest_rect);
      graphics_->present();

      frame_time = SDL_GetTicks() - frame_start;

      if(frame_time < delay_time) {
        SDL_Delay((int)(delay_time - frame_time));
      }
    }
  }

  void Game::stop() {
    running_ = false;
  }
}

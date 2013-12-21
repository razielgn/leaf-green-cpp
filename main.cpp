#include <iostream>
#include <cassert>
#include <SDL.h>
#include <SDL_image.h>

int main() {
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;

  if(SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
    window = SDL_CreateWindow("Hello there!",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              640,
                              480,
                              SDL_WINDOW_SHOWN);

    if(window) {
      renderer = SDL_CreateRenderer(window,
                                    -1,
                                    SDL_RENDERER_ACCELERATED |
                                    SDL_RENDERER_PRESENTVSYNC);
    }
  } else {
    return 1;
  }

  SDL_SetRenderDrawColor(renderer, 196, 236, 217, 255);

  SDL_Surface *hero = IMG_Load("hero.png");
  assert(hero);
  SDL_Texture *hero_texture = SDL_CreateTextureFromSurface(renderer, hero);
  assert(hero_texture);

  SDL_Rect source_rect, dest_rect;
  int scale = 4;


  bool running = true;

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

  while(running) {
    frame_start = SDL_GetTicks();

    key_state = SDL_GetKeyboardState(NULL);

    if(SDL_PollEvent(&event)) {
      switch(event.type) {
        case SDL_QUIT:
          running = false;
          break;
        case SDL_KEYDOWN:
          if(key_state[SDL_SCANCODE_ESCAPE]) {
            running = false;
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

      switch(direction) {
        case 0:
          dest_rect.y += 2;
          break;
        case 1:
          dest_rect.x -= 2;
          break;
        case 2:
          dest_rect.y -= 2;
          break;
        case 3:
          dest_rect.x += 2;
          break;
        default:
          break;
      }
    } else {
      source_rect.x = 0;
    }
    source_rect.y = frame_h * direction;

    dest_rect.w = source_rect.w * scale;
    dest_rect.h = source_rect.h * scale;

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, hero_texture, &source_rect, &dest_rect);
    SDL_RenderPresent(renderer);

    frame_time = SDL_GetTicks() - frame_start;

    if(frame_time < delay_time) {
      SDL_Delay((int)(delay_time - frame_time));
    }
  }

  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  return 0;
}

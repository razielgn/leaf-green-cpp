#!/usr/bin/env bash

clang $(pkg-config --cflags --libs sdl2) -lSDL2_Image -lstdc++ -Werror -Wextra -pedantic -o sdl_hello sdl_hello.cpp

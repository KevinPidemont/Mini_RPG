# How to install

This game use SDL2, so you need first to install SDL2.

## MacOS (via Homebrew)

Installing SDL2:

`$ brew install sdl2`

Installing SDL2_image:

`$ brew install sdl2_image`

Installing SDL_ttf:

`$ brew install sdl2-ttf`

# How to run

## Compiling with g++

`$ g++ main.cpp -o {my_output_file} $(sdl2-config --cflags --libs) -lSDL2_image -lSDL2_ttf`

#include <iostream>
#include <core.hpp>

int main() {
    SDL_Window *window;
    SDL_Renderer *renderer;

    init_sdl(renderer, window);
    loop_sdl(renderer, window);

    return 0;
}

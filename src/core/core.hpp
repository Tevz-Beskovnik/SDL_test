#pragma once

#include <log.hpp>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_timer.h>
#include <serializer.hpp>

void init_sdl(SDL_Renderer* &renderer, SDL_Window* &window) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
        LOG_ERROR(SDL_GetError());
        return;
    }

    if (IMG_Init(IMG_INIT_PNG) == 0) {
        LOG_ERROR(IMG_GetError());
        return;
    }

    window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
    if (window == NULL) {
        LOG_ERROR("Failed creating window");
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        LOG_ERROR("Failed creating renderer");
        return;
    }
}

void loop_sdl(SDL_Renderer* &renderer, SDL_Window* &window) {
    SDL_Surface* lettuce_sur = IMG_Load("/Users/tevz/Documents/programing/SDL_test/resources/desk.jpg");
    if (lettuce_sur == NULL) {
        LOG_ERROR(IMG_GetError());
        return;
    }

    SDL_Texture* lettuce_tex = SDL_CreateTextureFromSurface(renderer, lettuce_sur);
    if (lettuce_tex == NULL) {
        LOG_ERROR("Error creating texture");
        return;
    }

    SDL_FreeSurface(lettuce_sur);

    while (true) {
        SDL_Event e;
        if(SDL_WaitEvent(&e)) {
            if (e.type == SDL_QUIT) {
                LOG("Quit event");
                break;
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, lettuce_tex, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(lettuce_tex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}
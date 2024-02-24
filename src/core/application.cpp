//
// Created by Tevz on 23. 02. 24.
//

#include <application.hpp>

Application::Application(application_config config)
    : renderer(nullptr), window(nullptr), scene(nullptr)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
        LOG_ERROR(SDL_GetError());
        return;
    }

    if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0) {
        LOG_ERROR(IMG_GetError());
        return;
    }

    window = SDL_CreateWindow(config.title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, config.width, config.height, SDL_WINDOW_OPENGL);
    if (window == nullptr) {
        LOG_ERROR("Failed creating window");
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        LOG_ERROR("Failed creating renderer");
        return;
    }
}

Application::~Application() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

void Application::set_scene(Scene* scene) {
    this->scene = scene;
}

void Application::run() {
    running = true;

    while (running) {
        SDL_Event e;
        if(SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                LOG("Quit event");
                running = false;
                break;
            }

            scene->on_event(e);
        }

        scene->draw();
    }
}
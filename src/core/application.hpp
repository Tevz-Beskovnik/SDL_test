#pragma once

#include <string>
#include <SDL.h>
#include <scene.hpp>

struct application_config {
    int32_t width;
    int32_t height;
    std::string title;
};

class Application {
public:
    explicit Application(application_config config);

    ~Application();

    void set_scene(Scene* scene);

    void run();

    SDL_Renderer* get_renderer() { return renderer; }

    SDL_Window* get_window() { return window; }
private:
    SDL_Renderer* renderer;
    SDL_Window* window;

    bool running = false;

    Scene* scene;
};

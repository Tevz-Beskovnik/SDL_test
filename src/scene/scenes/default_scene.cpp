#include <default_scene.hpp>

DefaultScene::DefaultScene(const scene_config &config) : Scene(config) {
    LOG("DefaultScene created");
}

void DefaultScene::on_event_impl(const SDL_Event &e) {
    LOG("DefaultScene event");
    if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
            case SDLK_ESCAPE:
                LOG("Escape key pressed");
                break;
            case SDLK_w:
                w = true;
                break;
            case SDLK_s:
                s = true;
                break;
            case SDLK_a:
                a = true;
                break;
            case SDLK_d:
                d = true;
                break;
        }
    }

    if (e.type == SDL_KEYUP) {
        switch (e.key.keysym.sym) {
            case SDLK_w:
                w = false;
                break;
            case SDLK_s:
                s = false;
                break;
            case SDLK_a:
                a = false;
                break;
            case SDLK_d:
                d = false;
                break;
        }
    }
}

void DefaultScene::draw_impl() {
    // Camera controller
    source.x += (source.x + source.w < width && d) + -(source.x > 0 && a);
    source.y += (source.y + source.h < height && s) + -(source.y > 0 && w);
}
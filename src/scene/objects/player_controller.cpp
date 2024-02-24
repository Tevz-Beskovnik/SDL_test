#include <player_controller.hpp>

PlayerController::PlayerController(SDL_Renderer* renderer, int32_t x, int32_t y, std::string path, bool colidable)
    : Object(renderer, x, y, path, colidable)
{
    LOG("PlayerController created");
}

PlayerController::PlayerController(SDL_Renderer* renderer, int32_t x, int32_t y, int32_t w, int32_t h, std::string path, bool colidable)
    : Object(renderer, x, y, w, h, path, colidable)
{
    LOG("PlayerController created");
}

void PlayerController::draw() {
    rect.x += (d - a);
    rect.y += (s - w);

    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void PlayerController::on_event(const SDL_Event& e) {
    LOG("PlayerController event");
    if(e.type == SDL_KEYDOWN) {
        switch(e.key.keysym.sym) {
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

    if(e.type == SDL_KEYUP) {
        switch(e.key.keysym.sym) {
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
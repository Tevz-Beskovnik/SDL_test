#include <object.hpp>

Object::Object(SDL_Renderer* renderer, int32_t x, int32_t y, std::string path, bool colidable)
    : renderer(renderer), x(x), y(y), path(path), colidable(colidable)
{
    SDL_Surface* surf = IMG_Load(path.c_str());

    texture = SDL_CreateTextureFromSurface(renderer, surf);
    if (texture == nullptr) {
        LOG_ERROR(std::string("Failed to load texture: ") + path);
    }

    rect = {this->x, this->y, surf->w, surf->h};

    SDL_QueryTexture(texture, NULL, NULL, &this->rect.w, &this->rect.h);
}

Object::Object(SDL_Renderer *renderer, int32_t x, int32_t y, int32_t w, int32_t h, std::string path, bool colidable)
    : renderer(renderer), x(x), y(y), path(path), colidable(colidable)
{
    SDL_Surface* surf = IMG_Load(path.c_str());

    texture = SDL_CreateTextureFromSurface(renderer, surf);
    if (texture == nullptr) {
        LOG_ERROR(std::string("Failed to load texture: ") + path);
    }

    rect = {this->x, this->y, w, h};

    SDL_QueryTexture(texture, NULL, NULL, &this->rect.w, &this->rect.h);
}

Object::~Object() {
    SDL_DestroyTexture(texture);
}
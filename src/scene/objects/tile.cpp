#include <tile.hpp>

Tile::Tile(SDL_Renderer* renderer, int32_t x, int32_t y, std::string path, bool colidable) : Object(renderer, x, y, path, colidable) { LOG("Tile created"); }

Tile::Tile(SDL_Renderer* renderer, int32_t x, int32_t y, int32_t w, int32_t h, std::string path, bool colidable) : Object(renderer, x, y, w, h, path, colidable) { LOG("Tile created"); }

void Tile::draw() {
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void Tile::on_event(const SDL_Event& e) {}
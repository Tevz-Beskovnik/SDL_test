#pragma once
#include <object.hpp>
#include <object_types.hpp>
#include <SDL.h>

class PlayerController : public Object {
public:
    PlayerController(SDL_Renderer* renderer, int32_t x, int32_t y, std::string path, bool colidable = false);

    PlayerController(SDL_Renderer* renderer, int32_t x, int32_t y, int32_t w, int32_t h, std::string path, bool colidable = false);

    void draw() override;

    void on_event(const SDL_Event& e) override;

    int32_t type() override { return object_type::PLAYER; };
private:
    bool w, a, s, d;
};

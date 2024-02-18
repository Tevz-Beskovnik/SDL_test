#pragma once
#include <string>
#include <log.hpp>
#include <SDL.h>
#include <SDL_image.h>

class Object {
    public:
        Object(SDL_Renderer* renderer, int32_t x, int32_t y, std::string path, bool colidable = false);

        Object(SDL_Renderer* renderer, int32_t x, int32_t y, int32_t w, int32_t h, std::string path, bool colidable = false);

        ~Object();

        void set_position(int32_t x, int32_t y) { this->x = x; this->y = y; };

        virtual void draw() = 0;

        virtual void on_event(SDL_Event& e) = 0;

        bool colidable;

    protected:
        SDL_Texture* texture;
        SDL_Rect rect;
        SDL_Renderer* renderer;
        std::string path;
        int32_t x;
        int32_t y;
};
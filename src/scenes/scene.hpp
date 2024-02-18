#pragma once

#include <log.hpp>
#include <SDL.h>
#include <SDL_image.h>
#include <object.hpp>

class Scene {
public:
    Scene(int32_t width, int32_t height, std::string title);

    ~Scene();

    [[nodiscard]] uint32_t add_object(const Object* object);

private:

};
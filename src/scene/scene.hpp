#pragma once

#include <log.hpp>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <object.hpp>

struct scene_config {
    // scene setup
    SDL_Renderer *renderer;
    int32_t width;
    int32_t height;
    std::string title;

    // What screen coordinates to draw to
    int32_t dest_camera_x;
    int32_t dest_camera_y;
    int32_t dest_camera_w;
    int32_t dest_camera_h;

    // Where on the source texture to draw from
    int32_t src_camera_x;
    int32_t src_camera_y;
    int32_t src_camera_w;
    int32_t src_camera_h;
};

class Scene {
public:
    explicit Scene() = default;

    explicit Scene(const scene_config &config);

    ~Scene();

    void add_object(const Object *object);

    void on_event(const SDL_Event& e);

    void set_background(const std::string &path);

    void draw();

protected:
    virtual void on_event_impl(const SDL_Event &e) {};

    SDL_Rect source;
    SDL_Rect destination;
    SDL_Texture* source_texture;
    SDL_Renderer* renderer;

    std::vector<Object *> objects;
    std::vector<uint32_t> collidable_ids;

    std::string title;

    SDL_Texture* background_texture;
    std::string background;
};
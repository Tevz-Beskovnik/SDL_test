#pragma once

#include <scene.hpp>

class DefaultScene : public Scene {
public:
    explicit DefaultScene(const scene_config &config);

    void on_event_impl(const SDL_Event &e) override;

    void draw_impl() override;
private:
    bool w, a, s, d;
};
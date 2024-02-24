#include <iostream>
#include <core.hpp>
#include <application.hpp>
#include <default_scene.hpp>
#include <player_controller.hpp>
#include <tile.hpp>

int main() {
    /*SDL_Window *window;
    SDL_Renderer *renderer;

    init_sdl(renderer, window);
    loop_sdl(renderer, window);*/

    application_config config {
        .title = "Game",
        .width = 800,
        .height = 600
    };

    Application app(config);

    scene_config scene_config {
        .renderer = app.get_renderer(),
        .width = 1600,
        .height = 1200,
        .title = "Game",
        .dest_camera_x = 0,
        .dest_camera_y = 0,
        .dest_camera_w = 800,
        .dest_camera_h = 600,
        .src_camera_x = 0,
        .src_camera_y = 0,
        .src_camera_w = 800,
        .src_camera_h = 600
    };

    DefaultScene scene(scene_config);

    auto tile = new Tile(app.get_renderer(), 0, 0, "/Users/tevz/Documents/programing/SDL_test/resources/tile.png", false);

    auto player = new PlayerController(app.get_renderer(), 200, 160, "/Users/tevz/Documents/programing/SDL_test/resources/tile.png", false);

    scene.set_background("/Users/tevz/Documents/programing/SDL_test/resources/desk.jpg");
    scene.add_object(tile);
    scene.add_object(player);

    app.set_scene(&scene);

    app.run();

    return 0;
}

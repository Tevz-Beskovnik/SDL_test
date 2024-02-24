#include <scene.hpp>

Scene::Scene(const scene_config &config)
    : renderer(config.renderer), source({config.src_camera_x, config.src_camera_y, config.src_camera_w, config.src_camera_h}),
      destination({config.dest_camera_x, config.dest_camera_y, config.dest_camera_w, config.dest_camera_h}),
      background_texture(nullptr), source_texture(nullptr), width(config.width), height(config.height)
{
    source_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, config.width, config.height);
    if (source_texture == nullptr) {
        LOG_ERROR("Failed to create source texture");
    }

    LOG("Scene created");
}

Scene::~Scene() {
    for (auto &object : objects) {
        delete object;
    }

    if(background_texture != nullptr)
        SDL_DestroyTexture(background_texture);

    SDL_SetRenderTarget(renderer, nullptr);
    SDL_DestroyTexture(source_texture);
}

void Scene::on_event(const SDL_Event& e) {
    on_event_impl(e);

    for (auto &object : objects)
        object->on_event(e);
}

void Scene::draw() {
    SDL_RenderClear(renderer);
    SDL_SetRenderTarget(renderer, source_texture);
    SDL_RenderClear(renderer);

    if(background_texture != nullptr)
        SDL_RenderCopy(renderer, background_texture, NULL, NULL);

    draw_impl();

    for (auto &object : objects)
        object->draw();

    SDL_SetRenderTarget(renderer, nullptr);
    SDL_RenderCopy(renderer, source_texture, &source, &destination);
    SDL_RenderPresent(renderer);
}

void Scene::add_object(const Object *object) {
    objects.push_back(const_cast<Object*>(object));
    auto id = static_cast<uint32_t>(objects.size() - 1);
    objects[id]->register_objects(objects, collidable_ids, id);

    if(object->colidable)
        collidable_ids.push_back(id);

    LOG("Object added to scene");
}

void Scene::set_background(const std::string &path) {
    background = path;
    SDL_Surface* surf = IMG_Load(path.c_str());
    if (surf == nullptr) {
        LOG_ERROR("Failed to load background");
        return;
    }

    background_texture = SDL_CreateTextureFromSurface(renderer, surf);
    if (background_texture == nullptr) {
        LOG_ERROR("Failed to create texture from surface");
        return;
    }

    SDL_FreeSurface(surf);
}
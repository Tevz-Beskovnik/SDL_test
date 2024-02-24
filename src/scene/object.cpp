#include <object.hpp>

Object::Object(SDL_Renderer* renderer, int32_t x, int32_t y, std::string path, bool colidable)
    : renderer(renderer), rect({x, y, 0, 0}), path(path), colidable(colidable), objects(*new std::vector<Object *>()), collidable_ids(*new std::vector<uint32_t>()), object_id(-1)
{
    SDL_Surface* surf = IMG_Load(path.c_str());

    texture = SDL_CreateTextureFromSurface(renderer, surf);
    if (texture == nullptr) {
        LOG_ERROR(std::string("Failed to load texture: ") + path);
    }

    rect.w = surf->w;
    rect.h = surf->h;

    SDL_QueryTexture(texture, NULL, NULL, &this->rect.w, &this->rect.h);
}

Object::Object(SDL_Renderer *renderer, int32_t x, int32_t y, int32_t w, int32_t h, std::string path, bool colidable)
    : renderer(renderer), rect({x, y, w, h}), path(path), colidable(colidable), objects(*new std::vector<Object *>()), collidable_ids(*new std::vector<uint32_t>()), object_id(-1)
{
    SDL_Surface* surf = IMG_Load(path.c_str());

    texture = SDL_CreateTextureFromSurface(renderer, surf);
    if (texture == nullptr) {
        LOG_ERROR(std::string("Failed to load texture: ") + path);
    }

    SDL_QueryTexture(texture, NULL, NULL, &this->rect.w, &this->rect.h);
}

Object::~Object() {
    SDL_DestroyTexture(texture);
}

void Object::register_objects(std::vector<class Object *>& objects, std::vector<uint32_t>& collidable_ids, uint32_t id) {
    /*if (!default_value) {
        delete &this->objects;
        delete &this->collidable_ids;
        default_value = false;
    }*/

    LOG("Object registered");

    this->object_id = static_cast<int32_t>(id);
    this->objects = objects;
    this->collidable_ids = collidable_ids;

    LOG("Object registered");
}

int32_t Object::is_coliding(int32_t type) {
    if(object_id == -1)
        return false;

    for (auto &id : collidable_ids) {
        if (id == object_id || objects[id]->type() != type)
            continue;

        if (SDL_HasIntersection(&rect, &objects[id]->rect))
            return id;
    }

    return -1;
}

// serializer methods
/*std::string Object::serialize() {
    std::string serialized = "{\n" + std::to_string(x) + "\n" + std::to_string(y) + "\n" + std::to_string(rect.w) + "\n" + std::to_string(rect.h) + "\n" + path + "\n" + std::to_string(colidable) + "}\n";
    return serialized;
}

Object* Object::deserialize(std::string serialized) {
    std::stringstream ss(serialized);
    std::string x, y, w, h, path, colidable;

    std::getline(ss, x);
    std::getline(ss, x);
    std::getline(ss, y);
    std::getline(ss, w);
    std::getline(ss, h);
    std::getline(ss, path);
    std::getline(ss, colidable);

    return new Object(renderer, std::stoi(x), std::stoi(y), std::stoi(w), std::stoi(h), path, colidable == "1" ? true : false);
}*/
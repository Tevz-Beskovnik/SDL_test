#pragma once
#include <string>
#include <vector>
#include <log.hpp>
#include <SDL.h>
#include <SDL_image.h>
#include <sstream>

class Object {
    public:
        Object(SDL_Renderer* renderer, int32_t x, int32_t y, std::string path, bool colidable = false);

        Object(SDL_Renderer* renderer, int32_t x, int32_t y, int32_t w, int32_t h, std::string path, bool colidable = false);

        ~Object();

        virtual void draw() {};

        virtual int32_t type() { return -1; };

        virtual void on_event(const SDL_Event& e) {};

        void register_objects(std::vector<Object *>& objects, std::vector<uint32_t>& collidable_ids, uint32_t id);

        bool colidable;

        // serializer methods TODO later
        /*virtual std::string serialize() override;

        virtual Object* deserialize(std::string serialized) override;*/

    protected:
        int32_t is_coliding(int32_t type);

        std::vector<Object *>& objects;
        std::vector<uint32_t>& collidable_ids;
        bool default_value = true;

        SDL_Texture* texture;
        SDL_Rect rect;
        SDL_Renderer* renderer;
        std::string path;

    private:
        int32_t object_id;
};
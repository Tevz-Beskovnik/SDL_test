#pragma once

#include <fstream>

template<typename T>
class Serializer {
public:
    static void serialize(T* object, const std::string& filepath) {
        std::string data = object->serialize();
        std::ofstream file(filepath);

        file << data;
    };

    virtual ~Serializer() = default;
};

template<typename T>
class Deserializer {
public:
    static T *deserialize(const std::string& filepath) {
        std::string serialized;
        std::ifstream file(filepath);

        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                serialized += line + "\n";
            }
            file.close();
        } else {
            return nullptr;
        }

        T *object = new T();
        return object->deserialize(serialized);
    };

    virtual ~Deserializer() = default;
};
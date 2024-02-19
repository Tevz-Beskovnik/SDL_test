#pragma once

#include <string>

class Serializable {
public:
    virtual std::string serialize() = 0;

    virtual Serializable* deserialize(std::string serilized) = 0;

    virtual ~Serializable() = default;
};
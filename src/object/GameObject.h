#pragma once

#include <iostream>
#include <glm/glm.hpp>
#include <SDL2/SDL.h>
#include <memory>

#include "../graphics/sprite.h"


class GameObject{
    public:
        void Draw(std::string shaderKey, std::string textureKey);
        void setPosition(int x, int y);
        void setSize(int x, int y);
        glm::vec2 getPosition();
        glm::vec2 getSize();
        GameObject(std::string spriteName, std::string shaderName);
        ~GameObject();
    private:
        glm::vec2 position;
        glm::vec2 size;
        std::unique_ptr<Sprite> sprite;
};
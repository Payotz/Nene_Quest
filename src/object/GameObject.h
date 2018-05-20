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
        bool collideWith(GameObject *object);
        glm::vec2 getPosition();
        glm::vec2 getSize();
        SDL_Rect* getObjectRect();
        GameObject(std::string spriteName, std::string shaderName);
        ~GameObject();
    private:
        SDL_Rect objectRect;
        std::unique_ptr<Sprite> sprite;
};
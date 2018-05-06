#pragma once

#include <iostream>
#include <glm/glm.hpp>
#include <SDL2/SDL.h>
#include <memory>

#include "../graphics/sprite.h"


class GameObject{
    public:
        void Draw();

        GameObject(std::string spriteName, std::string shaderName);
        ~GameObject();
    private:
        int posx;
        int posy;
        std::make_unique<Sprite> sprite;
};
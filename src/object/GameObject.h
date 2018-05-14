#pragma once

#include <iostream>
#include <glm/glm.hpp>
#include <SDL2/SDL.h>
#include <memory>

#include "../graphics/sprite.h"


class GameObject{
    public:
        void Draw(std::string shaderKey, std::string textureKey,glm::vec2 pos,glm::vec2 size,GLfloat rotate,GLfloat z_depth);

        GameObject(std::string spriteName, std::string shaderName);
        ~GameObject();
    private:
        int posx;
        int posy;
        std::unique_ptr<Sprite> sprite;
};
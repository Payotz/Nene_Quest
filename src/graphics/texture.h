#pragma once

#include <GL/gl3w.h>
#include <glm/glm.hpp>

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Texture{
    public:
        void loadFile(std::string fileName);
        void Use();
        void Reset();

        Texture();
        ~Texture();

    private:
        GLuint textureObject;
};
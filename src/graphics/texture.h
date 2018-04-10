#pragma once

#include "GL/gl3w.h"

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Texture{
    public:
        void loadFile(std::string fileName);
        void Use();

        Texture();
        ~Texture();

    private:
        GLuint textureObject;
};
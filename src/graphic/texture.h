#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <GL/gl3w.h>
#include <SDL2/SDL_image.h>

class Texture{
    public:
        void loadTexture(std::string name, bool subTexture);
        void addSubTexture(std::string name);
        void addSubTextureIntoMap(std::string texName, std::string path);
        void iterateSubTexture();
        void switchSubTexture(std::string name);
        void Use();
        void Reset();
        std::string test;
        Texture(bool value);
        ~Texture();
    private:
        std::vector<SDL_Surface*> subtextures;
        std::map<std::string, SDL_Surface*> subtexture_map;
        GLuint texture;
        bool isPNG;
        bool subTextureEnabled;
        int imageIndex = 0;
        int IMAGEMAXINDEX;
};

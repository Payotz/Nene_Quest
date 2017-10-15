#pragma once
#include <iostream>
#include <unordered_map>
#include <memory>
#include <SDL2/SDL.h>
#include "../graphic/sprite.h"
#include "../graphic/shader.h"
#include "../graphic/rectangle.h"
#include "../graphic/particle.h"

class TextureManager{
    public:
        
        void addSprite(std::string spriteName, bool isPNG);
        Sprite* getSprite(std::string spriteName);
        void deleteSprite(std::string spriteName);

        void addShader(std::string name);
        Shader* getShader(std::string name);
        void deleteShader(std::string name);

        void addRectangle(std::string name,Rect* value);
        Rect* getRectangle(std::string name);
        void deleteRectangle(std::string name);

        void addParticle(std::string name, std::string spritePath,std::string vertShader,std::string fragShader,bool isAnimated,bool isPNG, int count);
        std::vector<Particle*> getParticle(std::string name);
        void deleteParticle(std::string name);

        static TextureManager* getInstance(){
            static TextureManager* instance = new TextureManager();
            return instance;
        }

        TextureManager(TextureManager const&) = delete;
        void operator= (TextureManager const&) = delete;

    private:
        static std::unordered_map <std::string, Sprite*> sprite_list;
        static std::unordered_map <std::string, Shader*> shader_list;
        static std::unordered_map <std::string, Rect*> rect_list;
        static std::unordered_map <std::string, std::vector<Particle*>> particle_list;
        static std::unordered_map <std::string, int> numParticles;
        TextureManager() {}
        ~TextureManager() {}
};
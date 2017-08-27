#ifndef GAMEOBJ_
#define GAMEOBJ_

#include <iostream>
#include <glm/glm.hpp>
#include <SDL2/SDL.h>
/* This is gonna be a long one, I bet */
class GameObject{
    public:
        virtual void initialize(std::string spriteName, std::string pathName, std::string vertPathName,std::string fragPathName,bool isAnimated) = 0;
        virtual void setPosition(glm::vec2 pos) = 0;
        virtual glm::vec2 getPosition() = 0;
        virtual void setSize(glm::vec2 pos) = 0;
        virtual void changeState(int state) = 0;
        virtual int getCurrentState() = 0;
        virtual void render() = 0;
        virtual void move(glm::vec2 pos) = 0;
        virtual void clean() = 0;
        virtual bool isCollidingWith(SDL_Rect value, glm::vec2 pos) = 0;
        virtual void update() = 0;
        virtual SDL_Rect getRect() = 0;
        virtual int getHP() = 0;
        virtual void setHP(int value) = 0;
        virtual bool getIsAttacked() = 0;
        virtual void setIsAttacked(bool value) = 0;
        virtual ~GameObject() {}
};
#endif
#ifndef GAMEOBJ_PLAYER_
#define GAMEOBJ_PLAYER_
#include <glm/glm.hpp>

#include "../manager/TextureManager.h"
#include "GameObject.h"


typedef enum {
    NONE,
    ATTACK
} ObjectState;

class Player : public GameObject{
    

    public:
        void initialize(std::string spriteName, std::string pathName, std::string vertPathName,std::string fragPathName,bool isAnimated);
        void setPosition(glm::vec2 pos);
        glm::vec2 getPosition();
        void setSize(glm::vec2 pos);
        void render();
        void move(glm::vec2 pos);
        void changeState(int state);
        bool isCollidingWith(SDL_Rect value, glm::vec2 pos);
        SDL_Rect getRect();
        void update();
        void clean();
        int getCurrentState();
        int getHP();
        void setHP(int value);
        bool getIsAttacked();
        void setIsAttacked(bool value);
        ~Player();
        Player(glm::vec2 pos, bool value);
    private:
        int currentState;
        glm::vec2 position;
        glm::vec2 size;
        glm::vec3 color;
        std::string spriteName;
        bool isPNG;
        bool isAttacked = false;
        int HP;
};

#endif
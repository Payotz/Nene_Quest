#ifndef GAMEOBJ_BOAR
#define GAMEOBJ_BOAR
#include "GameObject.h"
#include "../manager/TextureManager.h"


class Enemy : public GameObject{

public:
    virtual void initialize(std::string spriteName, std::string pathName, std::string vertPathName,std::string fragPathName,bool isAnimated);
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
    ~Enemy();
    Enemy(glm::vec2 pos, bool value);
private:
    int currentState;
    glm::vec2 position;
    glm::vec2 size;
    glm::vec3 color;
    std::string spriteName;
    bool isPNG;

    int HP;
};


#endif
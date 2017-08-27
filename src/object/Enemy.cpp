#include "Enemy.h"

//int timerCounter;
//int attackCounter;
bool EnemyAttacked;
int EnemyAttackedCounter;

void Enemy::initialize(std::string spriteName, std::string pathName, std::string vertPathName,std::string fragPathName,bool isAnimated){
    this->spriteName = spriteName;
    TextureManager::getInstance()->addSprite(spriteName,isPNG);
    TextureManager::getInstance()->getSprite(spriteName)->initialize(pathName,vertPathName,fragPathName,isAnimated);
}
void Enemy::setPosition(glm::vec2 pos){
    position = pos;
}

glm::vec2 Enemy::getPosition(){
    return position;
}

void Enemy::setSize(glm::vec2 pos){
    size = pos;
}
void Enemy::render(){
    if(EnemyAttacked){
        if((SDL_GetTicks () % 2) == 0)
            return;
    }
    TextureManager::getInstance()->getSprite(this->spriteName)->Draw(position,size,0,color,0);
}
void Enemy::move(glm::vec2 pos){

}
void Enemy::changeState(int state){
    this->currentState = state;
}
bool Enemy::isCollidingWith(SDL_Rect value, glm::vec2 pos){
    SDL_Point dummy;
    dummy.x = position.x + pos.x;
    dummy.y = position.y + pos.y;
    return SDL_PointInRect(&dummy,&value);
}
SDL_Rect Enemy::getRect(){
    SDL_Rect dummy;
    dummy.x = position.x;
    dummy.y = position.y;
    dummy.w = size.x;
    dummy.h = size.y;

    return dummy;
}
void Enemy::update(){
    if(EnemyAttacked){
        if(EnemyAttackedCounter == 60){
            EnemyAttacked = false;
            EnemyAttackedCounter = 0;
        }
        EnemyAttackedCounter++;
    }
}
void Enemy::clean(){

}
int Enemy::getCurrentState(){
    return currentState;
}

int Enemy::getHP(){
    return HP;
}

void Enemy::setHP(int value){
    HP = value;
}

bool Enemy::getIsAttacked(){
    return EnemyAttacked;
}

void Enemy::setIsAttacked(bool value){
    EnemyAttacked = value;
}

Enemy::~Enemy(){

}
Enemy::Enemy(glm::vec2 pos, bool value): size(pos), isPNG(value){
    //timerCounter = 0;
    //attackCounter = 0;
    EnemyAttackedCounter = 0;
    currentState = 0;
}
#include "Player.h"

int timerCounter;
int attackCounter;
int playerAttackCounter;

void Player::initialize(std::string spriteName, std::string pathName, std::string vertPathName,std::string fragPathName,bool isAnimated){
    this->spriteName = spriteName;
    TextureManager::getInstance()->addSprite(spriteName,isPNG);
    TextureManager::getInstance()->getSprite(spriteName)->initialize(pathName,vertPathName,fragPathName,isAnimated);
}

SDL_Rect Player::getRect(){
    SDL_Rect dummy;
    dummy.x = position.x;
    dummy.y = position.y;
    dummy.w = size.x;
    dummy.h = size.y;

    return dummy;
}

void Player::setPosition(glm::vec2 pos){
    position = pos;
}

glm::vec2 Player::getPosition(){
    return position;
}

void Player::setSize(glm::vec2 value){
    size = value;
}

void Player::changeState(int state){
    this->currentState = state;
}

int Player::getCurrentState(){
    return currentState;
}


void Player::render(){
    if(isAttacked){
        if((SDL_GetTicks() % 2) == 0)
            return;
    }
    TextureManager::getInstance()->getSprite(this->spriteName)->Draw(position,size,0,color,0);
}

bool Player::isCollidingWith(SDL_Rect value, glm::vec2 pos){
    SDL_Point dummy;
    dummy.x = position.x + pos.x;
    dummy.y = position.y + pos.y;
    return SDL_PointInRect(&dummy,&value);
}

void Player::move(glm::vec2 pos){
    this->position.x += pos.x;
    this->position.y += pos.y;
    if(position.x > 800 - (size.x / 2))
        position.x -= pos.x;
    if(position.x < 0 + (size.x / 2))
        position.x -= pos.x ;
    if(position.y > 600 - (size.y / 2))
        position.y -= pos.y ;
    if(position.y < 150 + (size.x / 2))
        position.y -= pos.y ;
}

void Player::update(){
    if(currentState == 0){
        if(timerCounter > 20){
            TextureManager::getInstance()->getSprite(this->spriteName)->getTexture()->Use();
            TextureManager::getInstance()->getSprite(this->spriteName)->getTexture()->iterateSubTexture();
            TextureManager::getInstance()->getSprite(this->spriteName)->getTexture()->Reset();
            timerCounter = 0;
        }
        timerCounter++;
    }
    if(currentState == 1){
        TextureManager::getInstance()->getSprite(this->spriteName)->getTexture()->Use();
        TextureManager::getInstance()->getSprite(this->spriteName)->getTexture()->switchSubTexture("Attack");
        TextureManager::getInstance()->getSprite(this->spriteName)->getTexture()->Reset();
        if(attackCounter == 10){
            currentState = 0;
            TextureManager::getInstance()->getSprite(this->spriteName)->getTexture()->Use();
            TextureManager::getInstance()->getSprite(this->spriteName)->getTexture()->switchSubTexture("Initial");
            TextureManager::getInstance()->getSprite(this->spriteName)->getTexture()->Reset();
            attackCounter = 0;
        }
        attackCounter ++;
    }
    if(isAttacked){
        if(playerAttackCounter == 60){
            isAttacked = false;
            playerAttackCounter = 0;
        }
        playerAttackCounter++;
    }
}

bool Player::getIsAttacked(){
    return isAttacked;
}

void Player::setIsAttacked(bool value){
    isAttacked = value;
}

int Player::getHP(){
    return HP;
}

void Player::setHP(int value){
    HP = value;
}

void Player::clean(){

}

Player::~Player(){
    
}

Player::Player(glm::vec2 pos,bool value): size(pos), isPNG(value){
    timerCounter = 0;
    attackCounter = 0;
    currentState = 0;
    playerAttackCounter = 0;
    HP = 800;
}
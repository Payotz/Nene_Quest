#include "GameObject.h"

void GameObject::Draw(std::string shaderKey, std::string textureKey){
    sprite->Draw(shaderKey,textureKey,glm::vec2(objectRect.x,objectRect.y),glm::vec2(objectRect.w,objectRect.h),0,0);
}

void GameObject::setPosition(int x, int y){
    objectRect.x = x;
    objectRect.y = y;
}

void GameObject::setSize(int w, int h){
    objectRect.w = w;
    objectRect.h = h;
}

void GameObject::setHP(int value){
    HP = value;
}
void GameObject::setMaxHP(int value){
    maxHP = value;
}

bool GameObject::collideWith(GameObject *object){
    return SDL_HasIntersection(&objectRect,object->getObjectRect());
}

glm::vec2 GameObject::getPosition(){
    return glm::vec2(objectRect.x,objectRect.y);
}

glm::vec2 GameObject::getSize(){
    return glm::vec2(objectRect.w,objectRect.h);
}

SDL_Rect* GameObject::getObjectRect(){
    return &objectRect;
}

int GameObject::getHP(){
    return HP;
}

int GameObject::getMaxHP(){
    return maxHP;
}

GameObject::GameObject(std::string spriteName, std::string shaderName){
    sprite = std::make_unique<Sprite>();
    sprite->addTexture("default",spriteName);
    sprite->addShader("default",shaderName);
}

GameObject::~GameObject(){
    
}
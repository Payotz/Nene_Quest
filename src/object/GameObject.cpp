#include "GameObject.h"

void GameObject::Draw(std::string shaderKey, std::string textureKey){
    sprite->Draw(shaderKey,textureKey,this->position,this->size,0,0);
}

void GameObject::setPosition(int x, int y){
    position.x = x;
    position.y = y;
}

void GameObject::setSize(int x, int y){
    size.x = x;
    size.y = y;
}

glm::vec2 GameObject::getPosition(){
    return position;
}

glm::vec2 GameObject::getSize(){
    return size;
}

GameObject::GameObject(std::string spriteName, std::string shaderName){
    sprite = std::make_unique<Sprite>();
    sprite->addTexture("default",spriteName);
    sprite->addShader("default",shaderName);
}

GameObject::~GameObject(){
    
}
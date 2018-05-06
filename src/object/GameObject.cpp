#include "GameObject.h"

void GameObject::Draw(){
    sprite->Draw();
}

GameObject::GameObject(std::string spriteName, std::string shaderName){
    sprite->addTexture("default",spriteName);
    sprite->addShader("default",shaderName);
}

GameObject::~GameObject(){
    
}
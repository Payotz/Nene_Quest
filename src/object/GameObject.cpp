#include "GameObject.h"

void GameObject::Draw(std::string shaderKey, std::string textureKey,glm::vec2 pos,glm::vec2 size,GLfloat rotate,GLfloat z_depth){
    sprite->Draw(shaderKey,textureKey,pos,size,rotate,z_depth);
}

GameObject::GameObject(std::string spriteName, std::string shaderName){
    sprite = std::make_unique<Sprite>();
    sprite->addTexture("default",spriteName);
    sprite->addShader("default",shaderName);
}

GameObject::~GameObject(){
    
}
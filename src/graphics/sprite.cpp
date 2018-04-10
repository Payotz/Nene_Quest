#include "sprite.h"

glm::mat4 projection_ = glm::ortho(0.0f,800.0f,600.0f,0.0f,-1.0f,1.0f);

float vertices_[] = {
    0.0f, 1.0f, 0.0f, 1.0f,
    1.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f, 

    0.0f, 1.0f, 0.0f, 1.0f,
    1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 0.0f, 1.0f, 0.0f
};

void Sprite::addShader(std::string key, std::string fileName){
    if (shader_list.find(key) == shader_list.end())
        return;
    shader_list[key] = std::make_shared<Shader>();
    shader_list[key]->loadFile(fileName);
}
void Sprite::deleteShader(std::string key){
    shader_list.erase(key);
}
void Sprite::addTexture(std::string key, std::string fileName){
    if(texture_list.find(key) == texture_list.end())
        return;
    texture_list[key] = std::make_shared<Texture>();
    texture_list[key]->loadFile(fileName);
}
void Sprite::deleteShader(std::string key){
    texture_list.erase(key);
}
void Sprite::Draw(std::string shaderKey, std::string textureKey){
    shader_list[shaderKey]->Use();
    texture_list[textureKey]->Use();
}
Sprite::Sprite(){

}

Sprite::~Sprite(){

}
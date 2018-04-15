#include "sprite.h"

glm::mat4 projection_ = glm::ortho(0.0f,800.0f,600.0f,0.0f,-1.0f,1.0f);

GLfloat vertices_[] = {
    0.0f, 1.0f, 0.0f,
    1.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 0.0f, 

    0.0f, 1.0f, 0.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 0.0f, 1.0f
};

void Sprite::addShader(std::string key, std::string fileName){
    if (shader_list.find(key) == shader_list.end())
        return;
    shader_list[key] = std::make_shared<Shader>(fileName);
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
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES,0,6);
}
Sprite::Sprite(){
    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);

    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices_),vertices_,GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3 * sizeof(GL_FLOAT),(GLvoid*) 0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

Sprite::~Sprite(){
    glBindVertexArray(0);
    glDeleteBuffers(1,&VBO);
    glDeleteVertexArrays(1,&VAO);
}
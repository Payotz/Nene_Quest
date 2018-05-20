#include "sprite.h"

glm::mat4 projection_ = glm::ortho(0.0f,800.0f,600.0f,0.0f,-1.0f,1.0f);

GLfloat vertices[] = {
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f, 
    
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f
};  

void Sprite::addShader(std::string key, std::string fileName){
    shader_list[key] = std::make_unique<Shader>(fileName);
}
void Sprite::deleteShader(std::string key){
    shader_list.erase(key);
}
void Sprite::addTexture(std::string key, std::string fileName){
    texture_list[key] = std::make_unique<Texture>();
    texture_list[key]->loadFile(fileName);
}
void Sprite::deleteTexture(std::string key){
    texture_list.erase(key);
}
void Sprite::Draw(std::string shaderKey, std::string textureKey,glm::vec2 pos,glm::vec2 size,GLfloat rotate,GLfloat z_depth){
    shader_list[shaderKey]->Use();

    //Black magic
    glm::mat4 model;
    model = glm::translate(model,glm::vec3(pos,z_depth));
    model = glm::rotate(model,rotate,glm::vec3(pos,1.0f));
    model = glm::translate(model,glm::vec3(-0.5f * size.x, -0.5f * size.y, z_depth));
    model = glm::scale(model,glm::vec3(size,1.0f));

    shader_list[shaderKey]->setMatrix4("model",model);
    shader_list[shaderKey]->setMatrix4("projection",projection_);
    
    glActiveTexture(GL_TEXTURE0);
    texture_list[textureKey]->Use();

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES,0,6);
    
    glBindVertexArray(0);
    shader_list[shaderKey]->Reset();
    texture_list[textureKey]->Reset();
}
Sprite::Sprite(){
    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);

    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    glVertexAttribPointer(0,4,GL_FLOAT,GL_FALSE,4 * sizeof(GL_FLOAT),(GLvoid*) 0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

Sprite::~Sprite(){
    glBindVertexArray(0);
    glDeleteBuffers(1,&VBO);
    glDeleteVertexArrays(1,&VAO);
}
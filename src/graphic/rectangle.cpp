#include "rectangle.h"

GLuint Rect::VAO;
GLuint VBO_;

glm::mat4 projection_ = glm::ortho(0.0f,800.0f,600.0f,0.0f,-1.0f,1.0f);

float vertices_[] = {
    0.0f, 1.0f, 0.0f, 1.0f,
    1.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f, 

    0.0f, 1.0f, 0.0f, 1.0f,
    1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 0.0f, 1.0f, 0.0f
};

Rect::Rect(){
    shader = new Shader();
}

Rect::~Rect(){

}

void Rect::initialize(std::string vertPathName,std::string fragPathName){
    shader->loadShader(vertPathName,fragPathName);

    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO_);
    glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER,VBO_);
        glBufferData(GL_ARRAY_BUFFER,sizeof(vertices_),vertices_,GL_STATIC_DRAW);
        glVertexAttribPointer(0,4,GL_FLOAT,GL_FALSE,4 * sizeof(GL_FLOAT),(GLuint*)0);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);
    shader->Reset();
}

void Rect::Use(){

}
void Rect::Reset(){

}
void Rect::Draw(glm::vec2 position, glm::vec2 size, GLfloat rotate, glm::vec3 color,GLfloat z_depth){
    //Set shader to be used
    shader->Use();
    
    //Black magic math.
    glm::mat4 model;
    model = glm::translate(model,glm::vec3(position, z_depth));
    model = glm::rotate(model,rotate,glm::vec3(position,1.0f));
    model = glm::translate(model,glm::vec3(-0.5f * size.x, -0.5f * size.y, z_depth));
    model = glm::scale(model,glm::vec3(size,1.0f));

    //Set variable "model" to be used in vertex shader
    shader->setMatrix4("model",model);
    //Sets variable "projection" to be used in vertex shader
    shader->setMatrix4("projection",projection_);
    //Sets configurations set inside the VAO
    glBindVertexArray(VAO);
    //Draw vertices
    glDrawArrays(GL_TRIANGLES,0,6);

    //Disable VAO
    glBindVertexArray(0);
    shader->Reset();
}
void Rect::Test(){
    texture->Reset();
    glBindVertexArray(0);
}
Shader* Rect::getShader(){
    return shader;
}
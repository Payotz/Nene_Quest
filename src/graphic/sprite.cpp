#include "sprite.h"
GLuint VBO;

GLuint Sprite::VAO;

glm::mat4 projection = glm::ortho(0.0f,800.0f,600.0f,0.0f,-1.0f,1.0f);

float vertices[] = {
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f, 
    
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f
};  

Sprite::Sprite(bool value){
    shader = std::make_unique<Shader>();
    texture = std::make_unique<Texture>(value);
}
 
Sprite::~Sprite(){
}

void Sprite::initialize(std::string spriteName,std::string vertPathName,std::string fragPathName, bool isAnimated){
    shader->loadShader(vertPathName,fragPathName);
    texture->loadTexture(spriteName, isAnimated);
    //Generate a VAO
    glGenVertexArrays(1,&VAO);
    //Generate a VBO
    glGenBuffers(1,&VBO);
    //Set VAO to copy configurations
    glBindVertexArray(VAO);
        //Set VBO to be filled with data
        glBindBuffer(GL_ARRAY_BUFFER,VBO);
        //Makes room in the VRAM inside the GPU, to fit vertices
        glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
        //Configure how the GPU would read in the data
        glVertexAttribPointer(0,4,GL_FLOAT,GL_FALSE,4 * sizeof(GL_FLOAT),(GLuint*)0);
        //Enable Array[0] in the GPU for the shader to take in as data
        glEnableVertexAttribArray(0);
        //Sets nothing to be filled with data
        glBindBuffer(GL_ARRAY_BUFFER,0);
    //Sets nothing to copy configurations
    glBindVertexArray(0);
    texture->Reset();
    shader->Reset();
}

std::unique_ptr<Texture> Sprite::getTexture(){
    return std::move(texture);
}

void Sprite::Draw(glm::vec2 pos, glm::vec2 size, GLfloat rotate, glm::vec3 color, GLfloat z_depth){
    //Set shader to be used
    shader->Use();

    //Black magic math.
    glm::mat4 model;
    model = glm::translate(model,glm::vec3(pos, z_depth));
    model = glm::rotate(model,rotate,glm::vec3(pos,1.0f));
    model = glm::translate(model,glm::vec3(-0.5f * size.x, -0.5f * size.y, z_depth));
    model = glm::scale(model,glm::vec3(size,1.0f));

    //Set variable "model" to be used in vertex shader
    shader->setMatrix4("model",model);
    //Sets variable "projection" to be used in vertex shader
    shader->setMatrix4("projection",projection);
    
    //Sets Texture to be used
    glActiveTexture(GL_TEXTURE0);
    texture->Use();
    //Sets configurations set inside the VAO
    glBindVertexArray(VAO);

    //Draw vertices
    glDrawArrays(GL_TRIANGLES,0,6);

    //Disable VAO
    glBindVertexArray(0);
    texture->Reset();
    shader->Reset();

}

void Sprite::Test(){
    std::cerr << texture->test << std::endl;
}

void Sprite::Reset(){
    texture->Reset();
    shader->Reset();
    glBindVertexArray(0);
}
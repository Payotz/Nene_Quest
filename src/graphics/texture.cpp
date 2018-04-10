#include "texture.h"

glm::mat4 projection_ = glm::ortho(0.0f,800.0f,600.0f,0.0f,-1.0f,1.0f);

float vertices_[] = {
    0.0f, 1.0f, 0.0f, 1.0f,
    1.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f, 

    0.0f, 1.0f, 0.0f, 1.0f,
    1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 0.0f, 1.0f, 0.0f
};

void Texture::loadFile(std::string fileName){
    SDL_Surface *image = IMG_load(fileName.c_str());
    glGenTextures(1,&textureObject);
    glBindTexture(GL_TEXTURE_2D,textureObject);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,image->w,image->h,0,GL_RGB,GL_UNSIGNED_BYTE,image->pixels);
    
}

void Texture::Use(){

}

Texture::Texture(){

}

Texture::~Texture(){

}
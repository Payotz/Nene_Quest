#include "texture.h"

void Texture::loadFile(std::string fileName){
    SDL_Surface *image = IMG_Load(fileName.c_str());
    glGenTextures(1,&textureObject);
    glBindTexture(GL_TEXTURE_2D,textureObject);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,image->w,image->h,0,GL_RGB,GL_UNSIGNED_BYTE,image->pixels);
    glBindTexture(GL_TEXTURE_2D,0);
}

void Texture::Use(){
    glBindTexture(GL_TEXTURE_2D,textureObject);
}

void Texture::Reset(){
    glBindTexture(GL_TEXTURE_2D,0);
}

Texture::Texture(){

}

Texture::~Texture(){

}
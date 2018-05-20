#include "texture.h"

void Texture::loadFile(std::string fileName){
    SDL_Surface *image = IMG_Load(fileName.c_str());
    if(image == NULL){
        std::cout << "Error loading texture file : " << fileName << std::endl;
        return;
    }
    glGenTextures(1,&textureObject);
    glBindTexture(GL_TEXTURE_2D,textureObject);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,image->w,image->h,0,GL_RGBA,GL_UNSIGNED_BYTE,image->pixels);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    
    glBindTexture(GL_TEXTURE_2D,0);
    SDL_FreeSurface(image);
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
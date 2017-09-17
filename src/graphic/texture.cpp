#include "texture.h"

void Texture::loadTexture(std::string name, bool subTexture){
    //Load Image Data
    test = name;
    SDL_Surface *image = IMG_Load(name.c_str());
    if(image == NULL){
        std::cerr << "[ERROR]Texture::loadTexture : IMG_ERROR_CODE: " << IMG_GetError() << std::endl;
        return;
    }
    //Generate Texture Object
    glGenTextures(1,&this->texture);
    //Sets Texture Object to be filled with data
    glBindTexture(GL_TEXTURE_2D,this->texture);
        //Makes room for texture and sends image data to the GPU
        if(!isPNG){
            glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,image->w,image->h,0,GL_RGB,GL_UNSIGNED_BYTE,image->pixels);
        }else{
            glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,image->w,image->h,0,GL_RGBA,GL_UNSIGNED_BYTE,image->pixels);
        }
        //Sets Texture configurations
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    //Sets nothing to be filled with data
    glBindTexture(GL_TEXTURE_2D,0);
    if(subTexture == false){
        SDL_FreeSurface(image);
    }else{
        subtextures.push_back(image);
        subtexture_map["Initial"] = image;
        IMAGEMAXINDEX = static_cast<int>(subtextures.size());
        this->subTextureEnabled = true;
    }
    std::cerr << "[INFORMATION]Texture::loadTexture() : Loaded Texture : " << name << std::endl;
    std::cerr << "[INFORMATION]Texture::loadTexture() : Subtexture Enabled is " << subTexture << " for " << name << std::endl;
}

void Texture::Use(){
    //Sets texture object to be used
    glBindTexture(GL_TEXTURE_2D,this->texture);
}

void Texture::addSubTexture(std::string name){
    if(!subTextureEnabled){
        std::cerr << "[ERROR]Texture::addSubTexture() : SubTextures Not Enabled for this texture " << std::endl;
        return;
    }
    std::cerr << "[INFORMATION]Texture::addSubTexture() : Adding Subtexture: " << name << std::endl;
    subtextures.push_back(IMG_Load(name.c_str()));
    std::cout << "[INFORMATION]Texture::addSubTexture() : Number of Subtextures : " << subtextures.size() << std::endl;
    int errCode = glGetError();
    if(errCode)
        std::cerr << "[ERROR] OpenGL Error : " << glGetError() << std::endl;
}

void Texture::addSubTextureIntoMap(std::string texName, std::string path){
    if(!subTextureEnabled){
        std::cerr << "[ERROR]Texture::addSubTextureIntoMap() : SubTextures Not Enabled for this texture " << std::endl;
        return;
    }
    std::cerr << "[INFORMATION]Texture::addSubTexture() : Adding Subtexture: " << path << std::endl;
    subtexture_map[texName] = IMG_Load(path.c_str());
    int errCode = glGetError();
    if(errCode)
        std::cerr << "[ERROR] OpenGL Error : " << glGetError() << std::endl;
}

void Texture::iterateSubTexture(){
    if(!subTextureEnabled){
        std::cout << "[ERROR]Texture::iterateSubTexture() : SubTextures Not Enabled for this texture " << std:: endl;
        return;
    }
    if(imageIndex == 0)
        imageIndex = 1;
    else
        imageIndex = 0;
    glGetError();
    glTexSubImage2D(GL_TEXTURE_2D,0,0,0,subtextures[imageIndex]->w,subtextures[imageIndex]->h,GL_RGBA,GL_UNSIGNED_BYTE,subtextures[imageIndex]->pixels);
    int errCode = glGetError();
    if(errCode)
        std::cerr << "[ERROR]Texture::iterateSubTexture() : OpenGL Error : " << glGetError() << std::endl;
}

void Texture::switchSubTexture(std::string name){
    if(!subTextureEnabled){
        std::cerr << "[ERROR]Texture::switchSubTexture() : SubTextures Not Enabled for this texture " << std::endl;
        return;
    }
    if(subtexture_map.count(name) < 0){
        std::cerr << "[ERROR]Texture::switchSubTexture() : There is no subtexture with the name : " << name << std::endl;
        return;
    }

    glGetError();
    glTexSubImage2D(GL_TEXTURE_2D,0,0,0,subtexture_map[name]->w,subtexture_map[name]->h,GL_RGBA,GL_UNSIGNED_BYTE,subtexture_map[name]->pixels);
    int errCode = glGetError();
    if(errCode)
        std::cerr << "[ERROR]Texture::switchSubTexture() : OpenGL Error : " << glGetError() << std::endl;
}

void Texture::Reset(){
    glBindTexture(GL_TEXTURE_2D,0);
}

Texture::~Texture(){
    
}

Texture::Texture(bool value):isPNG(value){

}
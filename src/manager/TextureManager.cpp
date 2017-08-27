#include "TextureManager.h"

std::map<std::string, Sprite*> TextureManager::sprite_list;
std::map<std::string, Shader*> TextureManager::shader_list;
std::map<std::string, Rect*> TextureManager::rect_list;

void TextureManager::addSprite(std::string spriteName,bool isPNG){
    std::cout << "[INFORMATION]TextureManager::addSprite() : Adding Sprite: " << spriteName << std::endl;
    sprite_list[spriteName] = new Sprite(isPNG);
}

Sprite* TextureManager::getSprite(std::string spriteName){
    if(sprite_list.find(spriteName) != sprite_list.end())
        return sprite_list[spriteName];
    else{
        std::cout << "[ERROR]TextureManager::getSprite() : Sprite Not Found: " << spriteName << std::endl;
        return nullptr;
    }
}

void TextureManager::deleteSprite(std::string spriteName){
    if(sprite_list.find(spriteName) != sprite_list.end())
        sprite_list.erase(spriteName);
    else{
        std::cout << "[ERROR]TextureManager::deleteSprite() : Sprite Not Found: " << spriteName << std::endl;
        return;
    }
}

void TextureManager::addShader(std::string name){
    shader_list[name] = new Shader();
}

Shader* TextureManager::getShader(std::string name){
    if(shader_list.find(name) != shader_list.end())
        return shader_list[name];
    else{
        std::cout << "[ERROR]TextureManager::getSahder(): Shader Not Found : " << name << std::endl;
        return nullptr;
    }
}

void TextureManager::deleteShader(std::string name){
    shader_list.erase(name);
}

void TextureManager::addRectangle(std::string name, Rect* value){
    std::cout << "[INFORMATION]TextureManager::addRectangle() : Adding Rectangle: " << name << std:: endl;
    rect_list[name] = value;
}

Rect* TextureManager::getRectangle(std::string name){
    return rect_list[name];
}

void TextureManager::deleteRectangle(std::string name){
    rect_list.erase(name);
}

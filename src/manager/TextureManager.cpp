#include "TextureManager.h"

std::unordered_map<std::string, std::unique_ptr<Sprite>> TextureManager::sprite_list;
std::unordered_map<std::string, std::unique_ptr<Shader>> TextureManager::shader_list;
std::unordered_map<std::string, std::unique_ptr<Rect>> TextureManager::rect_list;
std::unordered_map<std::string, std::vector<Particle*>> TextureManager::particle_list;
std::unordered_map<std::string, int> TextureManager::numParticles;

void TextureManager::addSprite(std::string spriteName,bool isPNG){
    std::cerr << "[INFORMATION]TextureManager::addSprite() : Adding Sprite: " << spriteName;
    sprite_list[spriteName] = std::make_unique<Sprite>(isPNG);
}

std::unique_ptr<Sprite> TextureManager::getSprite(std::string spriteName){
    if(sprite_list.find(spriteName) != sprite_list.end())
        return std::move(sprite_list[spriteName]);
    else{
        std::cerr << "[ERROR]TextureManager::getSprite() : Sprite Not Found: " << spriteName << std::endl;
        return std::move(sprite_list[spriteName]);
    }
}

void TextureManager::deleteSprite(std::string spriteName){
    if(sprite_list.find(spriteName) != sprite_list.end())
        sprite_list.erase(spriteName);
    else{
        std::cerr << "[ERROR]TextureManager::deleteSprite() : Sprite Not Found: " << spriteName << std::endl;
        return;
    }
}

void TextureManager::addShader(std::string name){
    shader_list[name] = std::make_unique<Shader>();
}

std::unique_ptr<Shader> TextureManager::getShader(std::string name){
    std::variant<std::unique_ptr<Shader>,std::monostate> pointer, monostate;
    if(shader_list.find(name) != shader_list.end())
        return std::move(shader_list[name]);
    else{
        std::cerr << "[ERROR]TextureManager::getShader(): Shader Not Found : " << name << std::endl;
        return {};
    }
}

void TextureManager::deleteShader(std::string name){
    shader_list.erase(name);
}

void TextureManager::addRectangle(std::string name, std::unique_ptr<Rect> value){
    std::cerr << "[INFORMATION]TextureManager::addRectangle() : Adding Rectangle: " << name << std:: endl;
    rect_list[name] = std::move(value);
}

std::unique_ptr<Rect> TextureManager::getRectangle(std::string name){
    return std::move(rect_list[name]);
}

void TextureManager::deleteRectangle(std::string name){
    rect_list.erase(name);
}

void TextureManager::addParticle(std::string name, std::string spritePath,std::string vertShader,std::string fragShader,bool isAnimated,bool isPNG, int count){
    numParticles[name] = count;
    for (int counter = 0; counter < count; counter++){
        Particle *particle = new Particle();
        particle->initialize(spritePath,vertShader,fragShader,isAnimated,isPNG);
        particle_list[name].push_back(particle);
    }
}

std::vector<Particle*> TextureManager::getParticle(std::string name){
    return particle_list[name];
}

void TextureManager::deleteParticle(std::string name){
    particle_list.erase(name);
}

#include "GameObjectManager.h"

std::map<std::string, GameObject*> GameObjectManager::gameobj_list;

void GameObjectManager::addGameObject(std::string name, GameObject* object){
    gameobj_list[name] = object;
}

GameObject* GameObjectManager::getGameObject(std::string name){
    if(gameobj_list.find(name) != gameobj_list.end())
        return gameobj_list[name];
    else{
        std::cerr << "[ERROR]GameObjectManager::getGameObject() : Name not found : " << name << std::endl;
        return nullptr;
    }
}

void GameObjectManager::removeGameObject(std::string name){
    if(gameobj_list.find(name) != gameobj_list.end())
        gameobj_list.erase(name);
    else{
        std::cerr << "[ERROR]GameObjectManager::removeGameObject() : Name not found : " << name << std::endl;
        return;
    }
}
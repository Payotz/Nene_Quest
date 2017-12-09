#include "GameObjectManager.h"

std::unordered_map<std::string, std::shared_ptr<GameObject>> GameObjectManager::gameobj_list;

void GameObjectManager::addGameObject(std::string name, std::shared_ptr<GameObject> object){
    gameobj_list[name] = (object);
}

std::shared_ptr<GameObject> GameObjectManager::getGameObject(std::string name){
    if(gameobj_list.find(name) != gameobj_list.end())
        return gameobj_list[name];
    else{
        std::cerr << "[ERROR]GameObjectManager::getGameObject() : Name not found : " << name << std::endl;
        return gameobj_list[name];
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
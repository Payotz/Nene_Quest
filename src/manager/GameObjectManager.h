#pragma once

#include <iostream>
#include <unordered_map>
#include "../object/GameObject.h"

class GameObjectManager{
    public:
        void addGameObject(std::string name, GameObject* object);
        GameObject*  getGameObject(std::string name);
        void removeGameObject(std::string name);

        static GameObjectManager* getInstance(){
            static GameObjectManager* instance = new GameObjectManager();
            return instance;
        }

    private:
        static std::unordered_map<std::string, GameObject*> gameobj_list;
};

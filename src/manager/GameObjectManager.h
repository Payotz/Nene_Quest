#pragma once

#include <iostream>
#include <unordered_map>
#include <memory>
#include "../object/GameObject.h"

class GameObjectManager{
    public:
        void addGameObject(std::string name, std::shared_ptr<GameObject> object);
        std::shared_ptr<GameObject> getGameObject(std::string name);
        void removeGameObject(std::string name);

        static GameObjectManager* getInstance(){
            GameObjectManager* instance = new GameObjectManager;
            return instance;
        }

    private:
        static std::unordered_map<std::string, std::shared_ptr<GameObject>> gameobj_list;
};

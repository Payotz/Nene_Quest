#pragma once

#include <iostream>
#include <unordered_map>
#include "../manager/TextureManager.h"
#include "../state/State.h"
#include "../state/FirstState.h"

class StateMachine{
    public:
        void initialize();
        void changeState(std::string fileName);
        void handleEvents();
        void update();
        void render();
        std::shared_ptr<State> getCurrentState();
        static StateMachine* getInstance(){
            static StateMachine* instance;
            return instance;
        }
        StateMachine(StateMachine const&) = delete;
        void operator= (StateMachine const&) = delete;
    
    private:
        static std::shared_ptr<State> currentState;
        StateMachine(){};
        ~StateMachine(){};
        static std::unordered_map<std::string, std::shared_ptr<State>> state_list;
};

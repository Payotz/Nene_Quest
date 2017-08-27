#ifndef STATEMAC__
#define STATEMAC__

#include <iostream>
#include <map>
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
        State* getCurrentState();
        static StateMachine* getInstance(){
            static StateMachine* instance;
            return instance;
        }
        StateMachine(StateMachine const&) = delete;
        void operator= (StateMachine const&) = delete;
    
    private:
        static State* currentState;
        StateMachine(){};
        ~StateMachine(){};
        static std::map<std::string, State*> state_list;
};

#endif
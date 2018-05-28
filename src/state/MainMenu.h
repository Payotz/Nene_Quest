#pragma once

#include "State.h"

class MainMenu : public State{
    public:
        void onEnter(bool twoPlayer);
        void handleEvents();
        void update();
        void render();
        void exit();
        ~MainMenu(){}
        bool getIsRunning();
        bool getIsChangeState();
        std::string getChangeStateKey();
    private:
        static bool restartFlag;
        static bool isRunning;
        bool isChangeState;
        std::string changeStateKey;
};


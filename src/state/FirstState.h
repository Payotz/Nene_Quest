#pragma once

#include <SDL2/SDL.h>

#include "State.h"

class FirstState : public State{
    public:
        void onEnter();
        void handleEvents();
        void update();
        void render();
        void exit();
        bool getRestartFlag();
        bool getIsRunning();
        FirstState();
        ~FirstState();
    private:
        static bool restartFlag;
        static bool isRunning;
};


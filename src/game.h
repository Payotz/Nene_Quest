#pragma once


#include <GL/gl3w.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <unordered_map>
#include <memory>

#include "state/FirstState.h"
#include "state/MainMenu.h"
#include "state/State.h"

class Game{
    friend class State;

    public:
        void initialize();
        void handleEvents();
        void update();
        void render();
        void cleanup();
        void setState(std::string key);

        bool isRunning = true;
        bool restartFlag = false;

    private:
        std::unordered_map<std::string,std::unique_ptr<State>> state_list;
        State* currentState;
};

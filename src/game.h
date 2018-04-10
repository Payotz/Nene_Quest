#pragma once


#include <GL/gl3w.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>

#include "state/FirstState.h"



class Game{

    public:
        void initialize();
        void handleEvents();
        void update();
        void render();
        void cleanup();

        bool isRunning = true;
        bool restartFlag = false;
};

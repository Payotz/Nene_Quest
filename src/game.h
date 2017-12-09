#pragma once

#if _WIN32
#include <gl/gl3w.h>
#include <windows.h>
#elif __linux__
#include <GL/gl3w.h>
#else
#endif

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <glm/glm.hpp>
#include "graphic/sprite.h"
#include "manager/StateMachine.h"


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

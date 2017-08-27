#ifndef GAME__
#define GAME__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <windows.h>
#include <gl/gl3w.h>
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
    private:
        ~Game(){}
};

#endif
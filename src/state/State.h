#pragma once

#include <memory>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include "../object/GameObject.h"

class State{
    public:
        virtual void onEnter(bool twoPlayer) = 0;
        virtual void handleEvents() = 0;
        virtual void update() = 0;
        virtual void render() = 0;
        virtual void exit() = 0;
        virtual ~State(){}
        virtual bool getIsRunning() = 0;
        virtual bool getIsChangeState() = 0;
        virtual std::string getChangeStateKey() = 0;
};

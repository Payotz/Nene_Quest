#pragma once

#include <memory>
#include "../object/GameObject.h"

class State{

    public:
        virtual void onEnter() = 0;
        virtual void handleEvents() = 0;
        virtual void update() = 0;
        virtual void render() = 0;
        virtual void exit() = 0;
        virtual ~State() {}
        bool isRunning;
    private:
        bool restartFlag;
};

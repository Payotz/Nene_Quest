#include "game.h"
#undef main
#define FRAMES_PER_SECOND 60

int main(int argc, char *argv[]){
    unsigned int fpsTicks = 0;
    std::unique_ptr<Game> game = std::make_unique<Game>();
    game->initialize();
    while(game->isRunning){
        fpsTicks = SDL_GetTicks();
        game->handleEvents();
        game->update();
        game->render();
        
        fpsTicks = SDL_GetTicks() - fpsTicks;
        if(fpsTicks < 1000 / FRAMES_PER_SECOND)
            SDL_Delay((1000/ FRAMES_PER_SECOND) - fpsTicks);
    }
    game->cleanup();
    return 0;
}
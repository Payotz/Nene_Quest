#include "game.h"
SDL_Window* window;
SDL_GLContext context;

Sprite *sprite;

FirstState *first;

void Game::initialize(){
    
    /* Initialize SDL */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,3);
    window = SDL_CreateWindow("Hello World!",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if(window == NULL){
        std::cout << "Window not created! : " << SDL_GetError() << std::endl;
        return;
    }

    /*Initialize IMG Loading Library */
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
    
    /* Create OpenGL Context */
    context = SDL_GL_CreateContext(window);
    if(context == NULL){
        std::cout << "Context not created! : " << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }

    /* Retrieve OpenGL libraries from OpenGL drivers inside computer GPU */
    if(gl3wInit() !=0){
        std::cout << "GL3W cannot be initialized! : " << std::endl;
        return;
    }
    std::cout << "[INFORMATION]OpenGL Version supported : " << glGetString(GL_VERSION) << std::endl;
    SDL_GL_SetSwapInterval(1);
    isRunning = true;
    StateMachine::getInstance()->initialize();
}

void Game::handleEvents(){
    StateMachine::getInstance()->handleEvents();
}

void Game::update(){
    isRunning = StateMachine::getInstance()->getCurrentState()->getIsRunning();
    restartFlag = StateMachine::getInstance()->getCurrentState()->getRestartFlag();
    StateMachine::getInstance()->update();

    if(restartFlag){
        cleanup();
        initialize();
        restartFlag = false;
    }
}

void Game::render(){
    //First, Paint the screen black.
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    StateMachine::getInstance()->render();
    //Refresh the window
    SDL_GL_SwapWindow(window);

}

void Game::cleanup(){
    delete(sprite);
    SDL_GL_DeleteContext(context);
    IMG_Quit();
    SDL_Quit();
}
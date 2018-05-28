#include "MainMenu.h"

bool MainMenu::isRunning;
std::unique_ptr<GameObject> btnNewGame;
std::unique_ptr<GameObject> btnQuit;

glm::vec2 mousePos;

void MainMenu::onEnter(bool twoPlayer){
    isChangeState = false;
    isRunning = true;
    btnNewGame = std::make_unique<GameObject>("img/btnNewGame.png","shader/default");
    btnNewGame->setPosition(300,300);
    btnNewGame->setSize(256,128);
    btnQuit = std::make_unique<GameObject>("img/btnQuit.png","shader/default");
}

void MainMenu::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);

    if(event.type == SDL_QUIT){
        isRunning = false;
    }

    if(event.type == SDL_MOUSEBUTTONUP){
        mousePos.x = event.button.x;
        mousePos.y = event.button.y;
    }

}

void MainMenu::render(){
    btnNewGame->Draw("default","default");
}

void MainMenu::update(){
    if(btnNewGame->pointInRect(glm::vec2(mousePos.x,mousePos.y))){
        changeStateKey = "game";
        isChangeState = true;
    }
}

void MainMenu::exit(){

}

bool MainMenu::getIsRunning(){
    return isRunning;
}

bool MainMenu::getIsChangeState(){
    return isChangeState;
}

std::string MainMenu::getChangeStateKey(){
    return changeStateKey;
}
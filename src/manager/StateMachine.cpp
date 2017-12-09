#include "StateMachine.h"

std::unordered_map<std::string, std::shared_ptr<State>> StateMachine::state_list;
std::shared_ptr<State> StateMachine::currentState;

std::shared_ptr<State> StateMachine::getCurrentState(){
    return currentState;
}

void StateMachine::initialize(){
    state_list["First"] = std::make_shared<FirstState>();
    currentState = state_list["First"];
    currentState->onEnter();
}

void StateMachine::changeState(std::string fileName){
    currentState->exit();
    currentState = state_list[fileName];
    currentState->onEnter();
}

void StateMachine::handleEvents(){
    currentState->handleEvents();
}

void StateMachine::render(){
    currentState->render();
}

void StateMachine::update(){
    currentState->update();
}
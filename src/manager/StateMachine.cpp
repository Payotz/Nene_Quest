#include "StateMachine.h"

std::unordered_map<std::string, State*> StateMachine::state_list;
State* StateMachine::currentState;

State* StateMachine::getCurrentState(){
    return currentState;
}

void StateMachine::initialize(){
    state_list["First"] = new FirstState();
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
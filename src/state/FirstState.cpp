#include "FirstState.h"

/*TODO: Implement Better Dragon fire
* TODO: Implement Dragon AI
*/

/* Velocity.x = cos(angle) / speed;
*  Velocity.y = sin(angle) / speed;
*/

bool FirstState::isRunning = true;
bool FirstState::restartFlag = false;

std::unique_ptr<GameObject> sample;

inline double degtoRad(int degree){
    return static_cast<double>((degree * 3.14) / 180);
}
inline int radtoDeg(double radian){
    return static_cast<int>((radian * 180) / 3.14);
}
void FirstState::onEnter(){

}

void FirstState::handleEvents(){
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
}

void FirstState::render(){
}

void FirstState::update(){
}

void FirstState::exit(){

}
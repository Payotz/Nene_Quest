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
    sample = std::make_unique<GameObject>("img/boar.png","shader/default");
    sample->setPosition(300,300);
    sample->setSize(200,200);
    
}

void FirstState::handleEvents(){
}

void FirstState::render(){
    sample->Draw("default","default");
}

void FirstState::update(){
}

void FirstState::exit(){

}
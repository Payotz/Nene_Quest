#include "FirstState.h"

/*TODO: Implement Better Dragon fire
* TODO: Implement Dragon AI
*/

/* Velocity.x = cos(angle) / speed;
*  Velocity.y = sin(angle) / speed;
*/

enum enumEnemyState{
    Boar,
    Dragon
};

bool FirstState::isRunning = true;
bool FirstState::restartFlag = false;
int enemyState = enumEnemyState::Boar;

std::unique_ptr<GameObject> sky;
std::unique_ptr<GameObject> mountain;
std::unique_ptr<GameObject> ground;

std::unique_ptr<GameObject> player1;
std::unique_ptr<GameObject> player2;

std::unique_ptr<GameObject> dragon;
std::unique_ptr<GameObject> boar; 

std::unique_ptr<GameObject> riceBall; 

void initRenderOnlyObjects();
inline double degtoRad(int degree);
inline int radtoDeg(double radian);

void FirstState::onEnter(){
    boar = std::make_unique<GameObject>("img/boar.png","shader/default");
    boar->setPosition(300,300);
    boar->setSize(50,50);
    
    initRenderOnlyObjects();
}

void FirstState::handleEvents(){
    const Uint8* keyState = SDL_GetKeyboardState(NULL);
    if(keyState[SDL_SCANCODE_Z])
        enemyState = enumEnemyState::Dragon;
    if(keyState[SDL_SCANCODE_X])
        enemyState = enumEnemyState::Boar;
}

void FirstState::render(){
    sky->Draw("default","default");
    mountain->Draw("default","default");
    ground->Draw("default","default");
    if(enemyState == enumEnemyState::Boar)
        boar->Draw("default","default");
    else if(enemyState == enumEnemyState::Dragon)
        return;
    else
        ;
}

void FirstState::update(){
    if(sky->getPosition().x < 0)
        sky->setPosition(1000,sky->getPosition().y);
    else
        sky->setPosition(sky->getPosition().x - 1,sky->getPosition().y);

    if(mountain->getPosition().x < 0)
        mountain->setPosition(800,mountain->getPosition().y);
    else
        mountain->setPosition(mountain->getPosition().x - 5,mountain->getPosition().y);
}

void FirstState::exit(){

}

void initRenderOnlyObjects(){
    sky = std::make_unique<GameObject>("img/sky.png","shader/default");
    mountain = std::make_unique<GameObject>("img/mountain.png","shader/default");
    ground = std::make_unique<GameObject>("img/ground.png","shader/default");

    sky->setPosition(0,200);
    sky->setSize(2000,600);

    mountain->setPosition(0,300);
    mountain->setSize(2000,400);

    ground->setPosition(0,500);
    ground->setSize(2000,400);
}

inline double degtoRad(int degree){
    return static_cast<double>((degree * 3.14) / 180);
}
inline int radtoDeg(double radian){
    return static_cast<int>((radian * 180) / 3.14);
}
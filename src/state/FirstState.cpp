#include "FirstState.h"

/*TODO: Implement Better Dragon fire
* TODO: Implement Dragon AI
*/

/* Velocity.x = cos(angle) / speed;
*  Velocity.y = sin(angle) / speed;
*/

enum class enumEnemyState{
    Boar,
    Dragon,
    NONE
};

enum class enumEnemyStatus{
    Neutral,
    isAttacked
};

enum class enumPlayerState{
    Neutral,
    Attack,
    Moving
};

bool FirstState::isRunning = true;
bool FirstState::restartFlag = false;
int enemyState = (int)enumEnemyState::Boar;
int enemyStatus = (int)enumEnemyStatus::isAttacked;
int player1State = (int)enumPlayerState::Neutral;
int player2State = (int)enumPlayerState::Neutral;

int player1InvulnerabilityTimer = 0;
int player2InvulnerabilityTimer = 0;
int enemyInvulnerabilityTimer = 0;

int player1AttackTimer = 0;
int player2AttackTimer = 0;

glm::vec2 player1Velocity;
glm::vec2 player2Velocity;

std::unique_ptr<GameObject> sky;
std::unique_ptr<GameObject> mountain;
std::unique_ptr<GameObject> ground;

std::unique_ptr<GameObject> player1HPBorder;
std::unique_ptr<GameObject> player1HP;
std::unique_ptr<GameObject> player1Icon;
std::unique_ptr<GameObject> player2HPBorder;
std::unique_ptr<GameObject> player2HP;
std::unique_ptr<GameObject> enemyIcon;
std::unique_ptr<GameObject> enemyHPBorder;
std::unique_ptr<GameObject> enemyHP;

std::unique_ptr<GameObject> player1;
std::unique_ptr<GameObject> player2;

std::unique_ptr<GameObject> dragon;
std::unique_ptr<GameObject> boar; 

std::unique_ptr<GameObject> riceBall; 

void initPlayerObjects(bool twoPlayer);
void initRenderOnlyObjects();
void initEnemyObjects();
inline double degtoRad(int degree);
inline int radtoDeg(double radian);

void backgroundScrolling();
void playerHPLimiter();
void playerPositionLimiter();
void playerAttackLogic(int playerDamage);
void playerReceiveDamageLogic();
void enemyAttackLogic();
void enemyReceiveDamageLogic();

void FirstState::onEnter(bool twoPlayer){
    initPlayerObjects(false);
    initRenderOnlyObjects();
    initEnemyObjects();
    isChangeState = false;

    player1Velocity.x = player1Velocity.y = 0;
    player2Velocity.x = player2Velocity.y = 0;
}

void FirstState::handleEvents(){
    const Uint8* keyState = SDL_GetKeyboardState(NULL);
    const int playerSpeed = 6;
    if(keyState[SDL_SCANCODE_Z])
        player1State = (int)enumPlayerState::Attack;
    if(player1State == (int)enumPlayerState::Neutral){
        if(keyState[SDL_SCANCODE_DOWN]){
            player1State = (int)enumPlayerState::Moving;
            player1Velocity.y = playerSpeed;
        }
        if(keyState[SDL_SCANCODE_UP]){
            player1State = (int)enumPlayerState::Moving;
            player1Velocity.y = playerSpeed * -1;
        }
        if(keyState[SDL_SCANCODE_RIGHT]){
            player1State = (int)enumPlayerState::Moving;
            player1Velocity.x = playerSpeed;
        }
        if(keyState[SDL_SCANCODE_LEFT]){
            player1State = (int)enumPlayerState::Moving;
            player1Velocity.x = playerSpeed * -1;
        }
    }

    SDL_Event event;
    SDL_PollEvent(&event);

    if(event.type == SDL_QUIT){
        isRunning = false;
    }
    if(event.type == SDL_KEYUP){
        player1State = (int)enumPlayerState::Neutral;
        player1Velocity.x = player1Velocity.y = 0;
        player1AttackTimer = 0;
    }
}

void FirstState::render(){
    sky->Draw("default","default");
    mountain->Draw("default","default");
    ground->Draw("default","default");
    
    if(player1State == (int)enumPlayerState::Attack){
        player1->Draw("default","attack");
    }else{
        player1->Draw("default","default");
    }

    if(enemyState == (int)enumEnemyState::Boar){
        if (enemyStatus == (int)enumEnemyStatus::isAttacked){
            if((SDL_GetTicks() % 2) == 0)
                ;
            else
                boar->Draw("default","default");
        }else{
            boar->Draw("default","default");
        }
        enemyHPBorder->Draw("default","default");
        enemyHP->Draw("default","default");
        enemyIcon->Draw("default","default");
    }else if(enemyState == (int)enumEnemyState::Dragon){
        if (enemyStatus ==(int)enumEnemyStatus::isAttacked){
            if((SDL_GetTicks() % 2)== 0){
                ;
            }else{
                dragon->Draw("default","default");
            }
        }else{
            dragon->Draw("default","default");
        }
        enemyHPBorder->Draw("default","default");
        enemyHP->Draw("default","default");
        enemyIcon->Draw("default","dragon");
    }

    player1HPBorder->Draw("default","default");
    player1HP->Draw("default","default");
    player1Icon->Draw("default","default");
}

void FirstState::update(){
    const int playerDamage = 25;

    playerAttackLogic(playerDamage);
    enemyReceiveDamageLogic();
    enemyAttackLogic();
    playerReceiveDamageLogic();
    if(player1State ==(int)enumPlayerState::Moving)
        player1->setPosition(player1->getPosition().x + player1Velocity.x, player1->getPosition().y + player1Velocity.y);

    backgroundScrolling();
    playerHPLimiter();
    playerPositionLimiter();

    float enemyDummyHP;
    float playerDummyHP;

    if(enemyState == (int) enumEnemyState::Boar){
        enemyDummyHP = ((float)boar->getHP())/boar->getMaxHP();
    }else if(enemyState == (int)enumEnemyState::Dragon){
        enemyDummyHP = ((float)dragon->getHP())/dragon->getMaxHP();
    }
    playerDummyHP = ((float)player1->getHP())/player1->getMaxHP();
    player1HP->setSize(int(playerDummyHP * 280),20);
    player1HPBorder->setSize(350,25);
    enemyHPBorder->setSize(350,25);
    enemyHP->setSize(int(enemyDummyHP * 280),20);
    if(boar->getHP() <= 0){
        enemyStatus = (int)enumEnemyStatus::Neutral;
        enemyState = (int)enumEnemyState::Dragon;
    }
    if(dragon->getHP() <= 0){
        enemyState = (int)enumEnemyStatus::Neutral;
        enemyState = (int)enumEnemyState::Dragon;
    }
}

void FirstState::exit(){

}

bool FirstState::getIsRunning(){
    return isRunning;
}

bool FirstState::getIsChangeState(){
    return isChangeState;
}

std::string FirstState::getChangeStateKey(){
    return changeStateKey;
}

void initPlayerObjects(bool twoPlayer){
    player1 = std::make_unique<GameObject>("img/pink_knight_500.png","shader/default");
    player1->getSprite()->addTexture("attack","img/pink_knight_500attackalt.png");
    player1->setSize(164,164);
    player1->setPosition(150,300);
    player1->setHP(100);
    player1->setMaxHP(100);

}

void initRenderOnlyObjects(){
    sky = std::make_unique<GameObject>("img/sky.png","shader/default");
    mountain = std::make_unique<GameObject>("img/mountain.png","shader/default");
    ground = std::make_unique<GameObject>("img/ground.png","shader/default");

    player1HP = std::make_unique<GameObject>("img/green_square.png","shader/hpBar");
    player2HP = std::make_unique<GameObject>("img/green_square.png","shader/hpBar");
    enemyHP = std::make_unique<GameObject>("img/green_square.png","shader/hpBar");
    player1HPBorder = std::make_unique<GameObject>("img/border_square.png","shader/default");
    player2HPBorder = std::make_unique<GameObject>("img/border_square.png","shader/default");
    enemyHPBorder = std::make_unique<GameObject>("img/border_square.png","shader/default");
    player1Icon = std::make_unique<GameObject>("img/pink_knight_icon.png","shader/default");
    enemyIcon = std::make_unique<GameObject>("img/boar.png","shader/default");

    enemyIcon->getSprite()->addTexture("dragon","img/dragon.png");

    sky->setPosition(0,200);
    sky->setSize(2000,600);

    mountain->setPosition(0,300);
    mountain->setSize(2000,400);

    ground->setPosition(0,500);
    ground->setSize(2000,400);

    player1HPBorder->setSize(int(((float)(player1->getHP())/player1->getMaxHP()) * 280),50);
    player1Icon->setSize(32,32);
    player1HP->setPosition(0,50);
    player1HPBorder->setPosition(0,50);
    player1Icon->setPosition(30,50);
    enemyHPBorder->setPosition(0,150);
    enemyHP->setPosition(0,150);
    enemyIcon->setSize(32,32);
    enemyIcon->setPosition(30,150);
}

void initEnemyObjects(){
    boar = std::make_unique<GameObject>("img/boar.png","shader/default");
    dragon = std::make_unique<GameObject>("img/dragon.png","shader/default");
    boar->setPosition(300,300);
    boar->setSize(128,128);
    boar->setHP(100);
    boar->setMaxHP(100);

    dragon->setPosition(700,400);
    dragon->setSize(512,512);
    dragon->setHP(300);
    dragon->setMaxHP(300);
}

void playerPositionLimiter(){
    if(player1->getPosition().x < 50)
        player1->setPosition(50,player1->getPosition().y);
    if(player1->getPosition().x > 750)
        player1->setPosition(750,player1->getPosition().y);
    if(player1->getPosition().y < 250)
        player1->setPosition(player1->getPosition().x,250);
    if(player1->getPosition().y > 550)
        player1->setPosition(player1->getPosition().x,550);
}

void playerHPLimiter(){
    if(player1->getHP() < 0)
        player1->setHP(player1->getMaxHP());
}

void backgroundScrolling(){
    if(sky->getPosition().x < 0)
        sky->setPosition(1000,sky->getPosition().y);
    else
        sky->setPosition(sky->getPosition().x - 1,sky->getPosition().y);

    if(mountain->getPosition().x < 0)
        mountain->setPosition(800,mountain->getPosition().y);
    else
        mountain->setPosition(mountain->getPosition().x - 5,mountain->getPosition().y);
}

void playerAttackLogic(int playerDamage){
    if(player1State == (int)enumPlayerState::Attack){
        if((SDL_GetTicks() - player1AttackTimer) >= 500){
            player1State = (int)enumPlayerState::Neutral;
            player1AttackTimer = 0;
        }
        player1AttackTimer = SDL_GetTicks();
        if(enemyStatus == (int)enumEnemyStatus::Neutral){
            if(enemyState == (int)enumEnemyState::Boar){
                if (player1->collideWith(boar.get())){
                    boar->setHP(boar->getHP() - playerDamage);
                    enemyStatus = (int)enumEnemyStatus::isAttacked;
                    enemyInvulnerabilityTimer = SDL_GetTicks();
                }
            }
            else if(enemyState == (int) enumEnemyState::Dragon){
                if(player1->collideWith(dragon.get())){
                    dragon->setHP(dragon->getHP() - playerDamage);
                    enemyStatus = (int)enumEnemyStatus::isAttacked;
                    enemyInvulnerabilityTimer = SDL_GetTicks();
                }
            }
        }
    }
}

void playerReceiveDamageLogic(){
    if(player1State ==(int)enumPlayerState::Neutral && enemyStatus ==(int) enumEnemyStatus::Neutral){
        if(enemyState ==(int)enumEnemyState::Boar){
            if(player1->collideWith(boar.get())){
                player1->setHP(player1->getHP() - 2);
            }
        }
        else if (enemyState == (int)enumEnemyState::Dragon){
            if(player1->collideWith(dragon.get())){
                player1->setHP(player1->getHP() - 2);
            }
        }
    }
}

void enemyAttackLogic(){
    if(enemyState == (int)enumEnemyState::Boar){
        if(boar->getPosition().x < 0){
            boar->setPosition(800,player1->getPosition().y);
        }
        if(enemyStatus != (int) enumEnemyStatus::isAttacked)
            boar->setPosition(boar->getPosition().x -20, boar->getPosition().y);
    }else if (enemyState == (int) enumEnemyState::Dragon){
        
    }
}

void enemyReceiveDamageLogic(){
    if(enemyState == (int) enumEnemyState::Boar){

    }else if (enemyState == (int)enumEnemyState::Dragon){

    }
    if(enemyStatus ==(int) enumEnemyStatus::isAttacked){
        if((SDL_GetTicks() - enemyInvulnerabilityTimer) >= 3000){
            enemyStatus = (int)enumEnemyStatus::Neutral;
            enemyInvulnerabilityTimer = 0;
        }
    }
}

inline double degtoRad(int degree){
    return static_cast<double>((degree * 3.14) / 180);
}
inline int radtoDeg(double radian){
    return static_cast<int>((radian * 180) / 3.14);
}
#include "FirstState.h"

bool FirstState::isRunning = true;
bool FirstState::restartFlag = false;

glm::vec2 pos;
glm::vec2 size;
glm::vec3 color;

glm::vec2 skypos;
glm::vec2 mountainpos;

int boarState;
int boarChargeCounter;
int dragonState;

glm::vec2 velocity;

int currentEnemy;

FirstState::FirstState(){
    velocity.x = 0;
    velocity.y = 0;
    boarState = 0;
    boarChargeCounter = 0;
    dragonState = 0;
    skypos = glm::vec2(0,200);
    mountainpos = glm::vec2(0,300);

    currentEnemy = 1;
}

FirstState::~FirstState(){
    GameObjectManager::getInstance()->removeGameObject("Player");
    GameObjectManager::getInstance()->removeGameObject("Boar1");
    GameObjectManager::getInstance()->removeGameObject("Dragon");

    TextureManager::getInstance()->deleteSprite("Sky");
    TextureManager::getInstance()->deleteSprite("Ground");
    TextureManager::getInstance()->deleteSprite("PlayerICON");
    TextureManager::getInstance()->deleteSprite("BoarICON");

    TextureManager::getInstance()->deleteRectangle("PlayerHP");
    TextureManager::getInstance()->deleteRectangle("EnemyHP");
}

void FirstState::onEnter(){
    GameObjectManager::getInstance()->addGameObject("Player",new Player(glm::vec2(164,164),true));
    GameObjectManager::getInstance()->getGameObject("Player")->initialize("Player","img/pink_knight_500.png","shader/Shader.vert","shader/Shader.frag",true);
    GameObjectManager::getInstance()->getGameObject("Player")->setPosition(glm::vec2(300,300));
    GameObjectManager::getInstance()->getGameObject("Player")->setHP(800);
    
    GameObjectManager::getInstance()->addGameObject("Boar1",new Enemy(glm::vec2(128,128),true));
    GameObjectManager::getInstance()->getGameObject("Boar1")->initialize("Boar1","img/boar.png","shader/Shader.vert","shader/Shader.frag",false);
    GameObjectManager::getInstance()->getGameObject("Boar1")->setPosition(glm::vec2(700,400));
    GameObjectManager::getInstance()->getGameObject("Boar1")->setHP(800);

    GameObjectManager::getInstance()->addGameObject("Dragon",new Enemy(glm::vec2(512,512),true));
    GameObjectManager::getInstance()->getGameObject("Dragon")->initialize("Dragon","img/dragon.png","shader/Shader.vert","shader/Shader.frag",false);
    GameObjectManager::getInstance()->getGameObject("Dragon")->setPosition(glm::vec2(800,400));
    GameObjectManager::getInstance()->getGameObject("Dragon")->setHP(800);

    TextureManager::getInstance()->addSprite("Sky",true);
    TextureManager::getInstance()->addSprite("Mountain",true);
    TextureManager::getInstance()->addSprite("Ground",true);

    TextureManager::getInstance()->addSprite("PlayerICON",true);
    TextureManager::getInstance()->addSprite("BoarICON",true);
    TextureManager::getInstance()->addSprite("DragonICON",true);

    TextureManager::getInstance()->getSprite("Sky")->initialize("img/sky.png","shader/Shader.vert","shader/bground.frag",false);
    TextureManager::getInstance()->getSprite("Mountain")->initialize("img/mountain.png","shader/Shader.vert","shader/Shader.frag",false);
    TextureManager::getInstance()->getSprite("Ground")->initialize("img/ground.png","shader/Shader.vert","shader/bground.frag",false);

    TextureManager::getInstance()->getSprite("PlayerICON")->initialize("img/pink_knight_icon.png","shader/Shader.vert","shader/Shader.frag",false);
    TextureManager::getInstance()->getSprite("BoarICON")->initialize("img/boar.png","shader/Shader.vert","shader/Shader.frag",false);
    TextureManager::getInstance()->getSprite("DragonICON")->initialize("img/dragon.png","shader/Shader.vert","shader/Shader.frag",false);

    TextureManager::getInstance()->getSprite("Player")->getTexture()->addSubTexture("img/pink_knight_500alt.png");
    TextureManager::getInstance()->getSprite("Player")->getTexture()->addSubTextureIntoMap("Attack","img/pink_knight_500attackalt.png");

    TextureManager::getInstance()->addRectangle("PlayerHP", new Rect());
    TextureManager::getInstance()->getRectangle("PlayerHP")->initialize("shader/hpbar.vert","shader/hpbar.frag");

    TextureManager::getInstance()->addRectangle("EnemyHP", new Rect());
    TextureManager::getInstance()->getRectangle("EnemyHP")->initialize("shader/hpbar.vert","shader/hpbar.frag");

}

void FirstState::handleEvents(){
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    const int playerMove = 9;
    if(GameObjectManager::getInstance()->getGameObject("Player")->getCurrentState() == 0){
        if(keystate[SDL_SCANCODE_DOWN])
            velocity.y = playerMove;
        if(keystate[SDL_SCANCODE_UP])
            velocity.y = playerMove * -1;
        if(keystate[SDL_SCANCODE_RIGHT])
            velocity.x = playerMove;
        if(keystate[SDL_SCANCODE_LEFT])
            velocity.x = playerMove * -1;
        if(keystate[SDL_SCANCODE_Z]){
            velocity.x = velocity.y = 0;
            GameObjectManager::getInstance()->getGameObject("Player")->changeState(1);
        }
        if(keystate[SDL_SCANCODE_F5])
            restartFlag = true;
    }
    
    SDL_Event event;
    SDL_PollEvent(&event);
    if(event.type == SDL_QUIT){
        isRunning = false;
    }
    if(event.type == SDL_KEYUP){
        velocity.x = velocity.y = 0;
    }
}

void FirstState::render(){
    auto PlayerHPvalue = GameObjectManager::getInstance()->getGameObject("Player")->getHP();

    if(PlayerHPvalue < 0)
        PlayerHPvalue = 0;

    TextureManager::getInstance()->getSprite("Sky")->Draw(skypos,glm::vec2(2000,600),0,color,0);
    TextureManager::getInstance()->getSprite("Mountain")->Draw(mountainpos,glm::vec2(2000,400),0,color,0);
    TextureManager::getInstance()->getSprite("Ground")->Draw(glm::vec2(0,500),glm::vec2(2000,400),0,color,0);
    if(currentEnemy == 1){
        auto EnemyHPvalue = GameObjectManager::getInstance()->getGameObject("Boar1")->getHP();
        glm::vec2 PlayerPosition = GameObjectManager::getInstance()->getGameObject("Player")->getPosition();
        glm::vec2 BoarPosition = GameObjectManager::getInstance()->getGameObject("Boar1")->getPosition();
        TextureManager::getInstance()->getRectangle("EnemyHP")->Draw(glm::vec2(0,550),glm::vec2(EnemyHPvalue,50),0,glm::vec4(255,0,0,255),0);
        TextureManager::getInstance()->getSprite("BoarICON")->Draw(glm::vec2(20,550),glm::vec2(32,32),0,color,0);
        if(PlayerPosition.y > BoarPosition.y){
            GameObjectManager::getInstance()->getGameObject("Boar1")->render();
            GameObjectManager::getInstance()->getGameObject("Player")->render();
        }else{
            GameObjectManager::getInstance()->getGameObject("Player")->render();
            GameObjectManager::getInstance()->getGameObject("Boar1")->render();
        }
    }else{
        auto EnemyHPvalue = GameObjectManager::getInstance()->getGameObject("Dragon")->getHP();
        glm::vec2 PlayerPosition = GameObjectManager::getInstance()->getGameObject("Player")->getPosition();
        glm::vec2 DragonPosition = GameObjectManager::getInstance()->getGameObject("Dragon")->getPosition();
        
        if(PlayerPosition.y > DragonPosition.y){
            GameObjectManager::getInstance()->getGameObject("Dragon")->render();
            GameObjectManager::getInstance()->getGameObject("Player")->render();   
        }else{
            GameObjectManager::getInstance()->getGameObject("Player")->render();
            GameObjectManager::getInstance()->getGameObject("Dragon")->render();
        }
        TextureManager::getInstance()->getRectangle("EnemyHP")->Draw(glm::vec2(0,550),glm::vec2(EnemyHPvalue,50),0,glm::vec4(255,0,0,255),0);
        TextureManager::getInstance()->getSprite("DragonICON")->Draw(glm::vec2(20,550),glm::vec2(32,32),0,color,0);
        if(EnemyHPvalue < 0)
            EnemyHPvalue = 0;
    }
    TextureManager::getInstance()->getRectangle("PlayerHP")->Draw(glm::vec2(0,50),glm::vec2(PlayerHPvalue,50),0,color,0);
    TextureManager::getInstance()->getSprite("PlayerICON")->Draw(glm::vec2(20,50),glm::vec2(32,32),0,color,0);
}

void FirstState::update(){
    color.x = color.y = color.z = 0.0;
    restartFlag = false;

    GameObjectManager::getInstance()->getGameObject("Player")->move(velocity);
    if(currentEnemy == 1){
            GameObjectManager::getInstance()->getGameObject("Boar1")->move(glm::vec2(-35,0));   
        
        if(GameObjectManager::getInstance()->getGameObject("Boar1")->getPosition().x < 0){
            if(boarChargeCounter >= 60){
                GameObjectManager::getInstance()->getGameObject("Boar1")->setPosition(glm::vec2(1000,GameObjectManager::getInstance()->getGameObject("Player")->getPosition().y));
                boarChargeCounter = 0;
            }
        }
        boarChargeCounter++;
        if(GameObjectManager::getInstance()->getGameObject("Boar1")->getHP() <= 0){
            currentEnemy++;
            GameObjectManager::getInstance()->getGameObject("Dragon")->setIsAttacked(true);
        }
        if(GameObjectManager::getInstance()->getGameObject("Player")->getCurrentState() == 0){
            if(GameObjectManager::getInstance()->getGameObject("Boar1")->isCollidingWith(GameObjectManager::getInstance()->getGameObject("Player")->getRect(),glm::vec2(0,0))){
                if(!GameObjectManager::getInstance()->getGameObject("Player")->getIsAttacked()){
                    GameObjectManager::getInstance()->getGameObject("Player")->setHP(GameObjectManager::getInstance()->getGameObject("Player")->getHP() - 25);
                    GameObjectManager::getInstance()->getGameObject("Player")->setIsAttacked(true);
                }
            }
        }
        else if(GameObjectManager::getInstance()->getGameObject("Player")->getCurrentState() == 1){
            if(GameObjectManager::getInstance()->getGameObject("Boar1")->isCollidingWith(GameObjectManager::getInstance()->getGameObject("Player")->getRect(),glm::vec2(-100,0))){
                if(!GameObjectManager::getInstance()->getGameObject("Boar1")->getIsAttacked()){
                    GameObjectManager::getInstance()->getGameObject("Boar1")->setHP(GameObjectManager::getInstance()->getGameObject("Boar1")->getHP() - 100);
                    GameObjectManager::getInstance()->getGameObject("Boar1")->setIsAttacked(true);
                }
            }
        }
        GameObjectManager::getInstance()->getGameObject("Boar1")->update();
    }else{
        if(currentEnemy != 1){
            if(GameObjectManager::getInstance()->getGameObject("Player")->getCurrentState() == 0){
                if(GameObjectManager::getInstance()->getGameObject("Dragon")->isCollidingWith(GameObjectManager::getInstance()->getGameObject("Player")->getRect(),glm::vec2(0,0))){
                    if(!GameObjectManager::getInstance()->getGameObject("Player")->getIsAttacked()){
                        GameObjectManager::getInstance()->getGameObject("Player")->setHP(GameObjectManager::getInstance()->getGameObject("Player")->getHP() - 200);
                        GameObjectManager::getInstance()->getGameObject("Player")->setIsAttacked(true);
                    }
                }
            }
            else if(GameObjectManager::getInstance()->getGameObject("Player")->getCurrentState() == 1){
                if(GameObjectManager::getInstance()->getGameObject("Dragon")->isCollidingWith(GameObjectManager::getInstance()->getGameObject("Player")->getRect(),glm::vec2(-100,0))){
                    if(!GameObjectManager::getInstance()->getGameObject("Dragon")->getIsAttacked()){
                        GameObjectManager::getInstance()->getGameObject("Dragon")->setHP(GameObjectManager::getInstance()->getGameObject("Dragon")->getHP() - 25);
                        GameObjectManager::getInstance()->getGameObject("Dragon")->setIsAttacked(true);
                    }
                }
            }
            GameObjectManager::getInstance()->getGameObject("Dragon")->update();
        }
    }
    GameObjectManager::getInstance()->getGameObject("Player")->update();
    if(skypos.x < 0)
        skypos.x = 1000;
    else
        skypos.x -= 1;

    if(mountainpos.x < 0)
        mountainpos.x = 800;
    else
        mountainpos.x -= 5;
}

void FirstState::exit(){

}

bool FirstState::getRestartFlag(){
    return restartFlag;
}
bool FirstState::getIsRunning(){
    return isRunning;
}
#include "particle.h"

Particle::Particle(): Position(0.0f), Velocity (0.0f), Color(0.0f), ParticleLife(0.0f){
    
}

Particle::~Particle(){

}

void Particle::initialize(std::string spritePathName,std::string vertPathName, 
                        std::string fragPathName, bool isAnimated, bool isPNG){
    sprite = new Sprite(isPNG);
    sprite->initialize(spritePathName,vertPathName,fragPathName,isAnimated);
}

void Particle::render(glm::vec2 origin,glm::vec2 limiter){
    auto dummy_x = (rand() % static_cast<int>(limiter.x)) + origin.x;
    auto dummy_y = (rand() % static_cast<int>(limiter.y)) + origin.y;

    sprite->Draw(glm::vec2(dummy_x,dummy_y),glm::vec2(16,16),0,glm::vec3(0,0,0),0);
}
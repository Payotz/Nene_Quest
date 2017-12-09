#pragma once

#include "sprite.h"
#include <stdlib.h>

class Particle{
public: 

    void initialize();

    glm::vec2 Position, Velocity;
    glm::vec4 Color;
    GLfloat ParticleLife;
    Particle();
    ~Particle();
    void initialize(std::string spritePathName,std::string vertPathName, 
                    std::string fragPathName, bool isAnimated, bool isPNG);
    void render(glm::vec2 origin,glm::vec2 limiter);

private:
    std::shared_ptr<Sprite> sprite;
};
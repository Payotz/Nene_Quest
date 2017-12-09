#pragma once

#ifdef _WIN32
#include <windows.h>
#include <gl/gl3w.h>
#elif __linux__
#include <GL/gl3w.h>
#else
#endif

#include <GL/glext.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/ext.hpp>
#include <glm/gtx/string_cast.hpp>
#include <memory>
#include <iostream>
#include "shader.h"
#include "texture.h"

class Sprite{
    public:
        Sprite(bool value);
        ~Sprite();
        void initialize(std::string spriteName,std::string vertPathName,std::string fragPathName, bool isAnimated);
        void Use();
        void Reset();
        void Draw(glm::vec2 position, glm::vec2 size, GLfloat rotate, glm::vec3 color,GLfloat z_depth);
        void Test();
        std::unique_ptr<Texture> getTexture();

        GLfloat ParticleLife;

    private:
        static GLuint VAO;
        std::unique_ptr<Shader> shader;
        std::unique_ptr<Texture> texture;
};


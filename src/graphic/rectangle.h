#pragma once

#include "shader.h"
#include "texture.h"
class Rect{
    public:
        Rect();
        ~Rect();
        void initialize(std::string vertPathName,std::string fragPathName);
        void Use();
        void Reset();
        void Draw(glm::vec2 position, glm::vec2 size, GLfloat rotate, glm::vec3 color,GLfloat z_depth);
        void Test();
        Shader* getShader();
    private:
        static GLuint VAO;
        Shader *shader;
        Texture *texture;
};

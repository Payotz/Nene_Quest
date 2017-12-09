#pragma once

#include "shader.h"
#include "texture.h"
#include <memory>
class Rect{
    public:
        Rect();
        ~Rect();
        void initialize(std::string vertPathName,std::string fragPathName);
        void Use();
        void Reset();
        void Draw(glm::vec2 position, glm::vec2 size, GLfloat rotate, glm::vec3 color,GLfloat z_depth);
        void Test();
        std::unique_ptr<Shader> getShader();
    private:
        static GLuint VAO;
        std::unique_ptr<Shader> shader;
        std::unique_ptr<Texture> texture;
};

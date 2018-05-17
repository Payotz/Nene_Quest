#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <GL/gl3w.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader{
    public:
        void loadShader(std::string vertFileName, std::string fragFileName);
        void Use();
        void Reset();
        ~Shader();

        void setMatrix4(std::string name, glm::mat4 &value);
        void setVector3f(std::string name, glm::vec3 value);
    private:
        GLuint program;
};

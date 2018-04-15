#pragma once

#include "GL/gl3w.h"

#include <string>
#include <ifstream>

class Shader{
    public:
        void Use();

        Shader(std::string fileName);
        ~Shader();

    private:
        GLuint shaderProgram;
};
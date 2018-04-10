#pragma once

#include "GL/gl3w.h"

#include <string>

class Shader{
    public:
        void loadFile(std::string fileName);
        void Use();

        Shader();
        ~Shader();
};
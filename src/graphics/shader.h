#pragma once

#include "GL/gl3w.h"

#include <string>
#include <fstream>
#include <GL/glext.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/ext.hpp>
#include <glm/gtx/string_cast.hpp>

class Shader{
    public:
        void Use();
        void Reset();
        void setMatrix4(std::string name, glm::mat4 &value);
        void setVector3f(std::string name, glm::vec3 value);
        Shader(std::string fileName);
        ~Shader();

    private:
        GLuint shaderProgram;
};
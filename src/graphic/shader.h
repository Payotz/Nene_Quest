#pragma once

#ifdef _WIN32
#include <windows.h>
#include <gl/gl3w.h>
#elif __linux__
#include <GL/gl3w.h>
#endif

#include <GL/gl.h>
#include <GL/glext.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <fstream>
#include <string>

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

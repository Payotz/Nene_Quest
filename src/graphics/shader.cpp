#include "shader.h"

void Shader::Use(){
    glUseProgram(shaderProgram);
}

Shader::Shader(std::string fileName){
    std::string vertexSource;
    std::string fragSource;
    std::ifstream vertexFile(fileName ~ ".vert");
    std::ifstream fragFile(fileName ~ ".frag");
    std::string line = "";
    while(!vertexFile.eof()){
        std::getline(vertexFile,line);
        vertexSource.append(line + "\n");
    }
    vertexFile.close();
    line = "";

    while(!fragFile.eof()){
        std::getline(fragFile,line);
        fragSource.append(line + "\n");
    }
    fragFile.close();
    line = "";

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertexShader,1,vertexSource.c_str(),NULL;
    glShaderSource(fragmentShader,1,fragSource.c_str(),NULL);

    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);

    glAttachShader(shaderProgram,vertexShader);
    glAttachShader(shaderProgram,fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::~Shader(){
    glDeleteProgram(shaderProgram);
}
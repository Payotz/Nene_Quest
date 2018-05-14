#include "shader.h"
#include <iostream>
#define GET_VARIABLE_NAME(Variable) (#Variable)

void checkShaderStatus(GLuint shader);
void checkProgramStatus(GLuint program);

void Shader::Use(){
    glUseProgram(shaderProgram);
}

void Shader::Reset(){
    glUseProgram(0);
}

void Shader::setMatrix4(std::string name,glm::mat4 &value){
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram,name.c_str()),1,GL_FALSE,glm::value_ptr(value));
}

void Shader::setVector3f(std::string name,glm::vec3 value){
    glUniform3f(glGetUniformLocation(shaderProgram,name.c_str()),value.x,value.y,value.z);
}

Shader::Shader(std::string fileName){
    std::string vertexSource;
    std::string fragSource;
    std::ifstream vertexFile(fileName + ".vert");
    if(!vertexFile.is_open()){
        std::cerr << "Shader Error. Could not open vertexFile" << std::endl;
        return;
    }
    std::ifstream fragFile(fileName + ".frag");
    if(!fragFile.is_open()){
        std::cerr << "Shader Error. Could not open fragFile" << std::endl;
        return;
    }
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

    const GLchar* vertexDummy = vertexSource.c_str();
    const GLchar* fragDummy = fragSource.c_str();

    glShaderSource(vertexShader,1,&vertexDummy,NULL);
    glShaderSource(fragmentShader,1,&fragDummy,NULL);

    glCompileShader(vertexShader);
    checkShaderStatus(vertexShader);
    glCompileShader(fragmentShader);
    checkShaderStatus(fragmentShader);

    glAttachShader(shaderProgram,vertexShader);
    glAttachShader(shaderProgram,fragmentShader);
    glLinkProgram(shaderProgram);
    checkProgramStatus(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::~Shader(){
    glDeleteProgram(shaderProgram);
}


void checkShaderStatus(GLuint shader){
    int success;
    char infoLog[1024];
    glGetShaderiv(shader,GL_COMPILE_STATUS,&success);
    if(!success){
        glGetShaderInfoLog(shader,1024,NULL,infoLog);
        std::cerr << "ERROR: " << GET_VARIABLE_NAME(shader) << " did not compile! " << infoLog << std::endl;
    }
}

void checkProgramStatus(GLuint program){
    int success;
    char infoLog[1024];
    glGetProgramiv(program,GL_LINK_STATUS,&success);
    if(!success){
        glGetProgramInfoLog(program,1024,NULL,infoLog);
        std::cerr << "ERROR: " << GET_VARIABLE_NAME(program) << " did not link! " << infoLog << std::endl;
    }
}
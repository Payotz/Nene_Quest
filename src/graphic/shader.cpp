#include "shader.h"

#define GET_VARIABLE_NAME(Variable) (#Variable)

void checkShaderStatus(GLuint shader);
void checkProgramStatus(GLuint program);

GLuint vertexShader;
GLuint fragmentShader;

void Shader::loadShader(std::string vertFileName, std::string fragFileName){
    std::string vertexFile;
    std::string fragmentFile;

    const char* vertexSource;
    const char* fragmentSource;

    // Copying text files into memory

    std::ifstream myFile;
    myFile.open(vertFileName);
    std::string line = "";
    while(!myFile.eof()){
        std::getline(myFile,line);
        vertexFile.append(line + "\n");
    }
    myFile.close();
    line = "";

    myFile.open(fragFileName);
    while(!myFile.eof()){
        std::getline(myFile,line);
        fragmentFile.append(line + "\n");
    }
    myFile.close();

    vertexSource = vertexFile.c_str();
    fragmentSource = fragmentFile.c_str();

    //Create vertex and fragment shader objects
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    
    //Point the vertex and fragment shader objects to the text files in memory
    glShaderSource(vertexShader,1,&vertexSource,NULL);
    glShaderSource(fragmentShader,1,&fragmentSource,NULL);
    
    //Compile Shaders
    glCompileShader(vertexShader);
    checkShaderStatus(vertexShader);
    glCompileShader(fragmentShader);
    checkShaderStatus(fragmentShader);

    //Create shader program pbject
    program = glCreateProgram();
    //Link compiled vertex and fragment shaders into the program
    glAttachShader(program,vertexShader);
    glAttachShader(program,fragmentShader);
    glLinkProgram(program);
    checkProgramStatus(program);

    //Delete vertex and fragment shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::Use(){
    //Set shader program to be used
    glUseProgram(program);    
}

void Shader::Reset(){
    glUseProgram(0);
}

Shader::~Shader(){
    glDeleteProgram(program);
}

void Shader::setMatrix4(std::string name, glm::mat4 &value){
    glUniformMatrix4fv(glGetUniformLocation(program,name.c_str()),1,GL_FALSE,glm::value_ptr(value));
}

void Shader::setVector3f(std::string name, glm::vec3 value){
    glUniform3f(glGetUniformLocation(program,name.c_str()),value.x,value.y,value.z);
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
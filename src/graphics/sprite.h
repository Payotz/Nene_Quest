#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include <glm/glm.hpp>


#include "shader.h"
#include "texture.h"
class Sprite{
    public:
        void addShader(std::string key, std::string fileName);
        void deleteShader(std::string key);
        void addTexture(std::string key, std::string fileName);
        void deleteShader(std::string key);
        void Draw(std::string shaderKey, std::string textureKey);
        Sprite();
        ~Sprite();
    private:
        std::unordered_map<std::string,std::shared_ptr<Shader>> shader_list;
        std::unordered_map<std::string,std::shared_ptr<Texture>> texture_list;
        GLuint VAO;
        GLuint VBO;
};
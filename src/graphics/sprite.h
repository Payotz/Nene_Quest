#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include <glm/glm.hpp>
#include <SDL2/SDL_image.h>
#include <GL/gl3w.h>

#include <GL/glext.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/ext.hpp>
#include <glm/gtx/string_cast.hpp>

#include "shader.h"
#include "texture.h"
class Sprite{
    public:
        void addShader(std::string key, std::string fileName);
        void deleteShader(std::string key);
        void addTexture(std::string key, std::string fileName);
        void deleteTexture(std::string key);
        void Draw(std::string shaderKey, std::string textureKey,glm::vec2 pos,glm::vec2 size,GLfloat rotate,GLfloat z_depth);
        Sprite();
        ~Sprite();
    private:
        std::unordered_map<std::string,std::unique_ptr<Shader>> shader_list;
        std::unordered_map<std::string,std::unique_ptr<Texture>> texture_list;
        GLuint VAO;
        GLuint VBO;
};
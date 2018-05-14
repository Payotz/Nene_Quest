#version 330 core
layout (location = 0) in vec4 aPos;

out vec2 TexCoord;

uniform mat4 model;
uniform mat4 projection;

void main()
{
    TexCoord = aPos.zw;
    gl_Position = projection * model * vec4(aPos.x, aPos.y, 0.0, 1.0);
}
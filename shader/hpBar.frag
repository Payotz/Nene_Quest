#version 330 core
out vec4 color;

in vec2 TexCoord;

uniform sampler2D image;

void main()
{
    color = vec4(0,255,0,255);
} 
/* 
    Fragment Shader
*/
#version 330 core
out vec4 color;

in vec2 TexCoord;

uniform sampler2D image;

void main()
{
    vec4 texColor = texture(image,TexCoord);
    color = texColor;
} 
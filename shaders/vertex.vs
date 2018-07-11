#version 450 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

uniform mat4 transform;
uniform mat4 view;
uniform mat4 project;

out vec2 TexCoord;
void main()
{
    TexCoord = aTexCoord;
    gl_Position = project * view * transform * vec4(aPos, 1.0f);
    //gl_Position = project * view * vec4(aPos, 1.0f);
}
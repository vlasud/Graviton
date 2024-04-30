#vertex

#version 460 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 color;

out vec4 fragmentColor;

uniform mat4 transform;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * transform * position;
    fragmentColor = position;
}

#fragment

#version 460 core

in vec4 fragmentColor;

out vec4 color;

void main()
{
    color = fragmentColor;
}
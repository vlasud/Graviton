#vertex

#version 460 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 color;

out vec4 fragmentColor;

void main()
{
    gl_Position = position + vec4(0, 0, 0, 0);
    fragmentColor = color;
}

#fragment

#version 460 core

in vec4 fragmentColor;

out vec4 color;

void main()
{
    color = vec4(1, 1, 1, 1);
}
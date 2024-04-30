#vertex

#version 460 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 color;

out vec4 fragmentColor;

uniform mat4 transform;
uniform mat4 view;

void main()
{
    gl_Position = view * transform * position;

    vec4 resColor = mix(vec4(1, 1, 1, 1), vec4(0, 0, 0, 1), 0.9);
    fragmentColor = resColor;
}

#fragment

#version 460 core

in vec4 fragmentColor;

out vec4 color;

void main()
{
    color = fragmentColor;
}
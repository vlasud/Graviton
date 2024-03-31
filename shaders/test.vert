#version 400

out vec4 color;

void main()
{
    gl_Position = gl_Vertex + vec4(0, 0.5, 0, 0);
}
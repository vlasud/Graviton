#include <render/shaderProgram.h>


ShaderProgram::ShaderProgram() :
    id(glCreateProgram()), error(0)
{
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(id);
}

void ShaderProgram::addShader(const std::string& path)
{
    Shader shader(path);
    glAttachShader(id, shader.getId());

    shaders.push_back(std::move(shader));
}
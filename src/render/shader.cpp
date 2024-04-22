#include <render/shader.h>

#include <fstream>
#include <cassert>


Shader::Shader(const std::string& shader_path) :
    programId(0)
{
    programId = glCreateProgram();

    std::ifstream stream(shader_path);
    assert(stream.is_open());

    uint32_t currentShaderType = 0, newShaderType = 0;
    std::string shaderSource, line;
    bool isStartShaderSource = false, isFileEnd = false;

    while (!isFileEnd)
    {
        std::getline(stream, line);
        isFileEnd = stream.eof();

        if (line.find("#vertex") != std::string::npos)
        {
            newShaderType = GL_VERTEX_SHADER;
            if (!currentShaderType)
                currentShaderType = newShaderType;
            isStartShaderSource = true;
        }
        else if (line.find("#fragment") != std::string::npos)
        {
            newShaderType = GL_FRAGMENT_SHADER;
            if (!currentShaderType)
                currentShaderType = newShaderType;
            isStartShaderSource = true;
        }

        if (isStartShaderSource || isFileEnd)
        {
            isStartShaderSource = false;
            if (isFileEnd)
                shaderSource += line;
            if (!shaderSource.empty())
            {
                uint32_t shaderId = glCreateShader(currentShaderType);
                const char* source_c = shaderSource.c_str();
                glShaderSource(shaderId, 1, &source_c, nullptr);
                glCompileShader(shaderId);
                GLint success;
                glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
                assert(success); // TODO: handle
                glAttachShader(programId, shaderId);
                glDeleteShader(shaderId);
                shaderSource.clear();
            }
            currentShaderType = newShaderType;
            continue;
        }

        shaderSource += line + '\n';
    }

    glLinkProgram(programId);
    stream.close();
}

Shader::~Shader()
{
    glDeleteProgram(programId);
}

void Shader::use()
{
    glUseProgram(programId);
}
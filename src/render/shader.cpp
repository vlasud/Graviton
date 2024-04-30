#include <render/shader.h>

#include <fstream>
#include <cassert>
#include <iostream>

Shader::Shader(const std::vector<std::string>& shader_files) :
    programId(0)
{
    programId = glCreateProgram();

    for (auto& shaderFile : shader_files)
    {
        std::ifstream stream(shaderFile);
        if (!stream.is_open())
        {
            // TODO: handle
            continue;
        }

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
                    if (!success)
                    {
                        char buffer[512];
                        glGetShaderInfoLog(shaderId, 512, 0, buffer);
                        std::cout << buffer << std::endl;
                    }
                    glAttachShader(programId, shaderId);
                    glDeleteShader(shaderId);
                    shaderSource.clear();
                }
                currentShaderType = newShaderType;
                continue;
            }

            shaderSource += line + '\n';
        }
        stream.close();
    }
    glLinkProgram(programId);
}

Shader::~Shader()
{
    glDeleteProgram(programId);
}

void Shader::use()
{
    glUseProgram(programId);
}
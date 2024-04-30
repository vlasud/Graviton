#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <string>
#include <vector>

class Shader
{
    uint32_t programId;

public:

    explicit Shader(const std::vector<std::string>& shader_files);
    virtual ~Shader();

    void use();
    __forceinline uint32_t getProgramId() const { return programId; }
};
#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <string>

class Shader
{
	uint32_t programId;

public:

	explicit Shader(const std::string& shader_path);
	virtual ~Shader();

	void use();
};
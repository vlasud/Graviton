#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <string>

class Shader
{
	uint32_t id;

public:

	Shader(const std::string& path);
	~Shader();

	__forceinline uint32_t getId() const { return id; }
};
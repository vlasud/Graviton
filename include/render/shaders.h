#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <string>
#include <vector>

class Shader
{
	uint32_t id;

public:

	Shader(const std::string& path);
	~Shader();

	__forceinline uint32_t getId() const { return id; }
};

class ShaderProgram final
{
	uint32_t id;
	int error;
	std::vector<Shader> shaders;

	ShaderProgram() = delete;
	ShaderProgram(const ShaderProgram&) = delete;
	ShaderProgram(const ShaderProgram&&) = delete;
	ShaderProgram& operator = (const ShaderProgram&) = delete;
	ShaderProgram& operator = (const ShaderProgram&&) = delete;

	void addShader(const std::string& path);

public:

	ShaderProgram(const std::string &path_to_shaders);
	~ShaderProgram();

	__forceinline uint32_t getId() const { return id; }
	__forceinline void use() const { glUseProgram(id); };
};
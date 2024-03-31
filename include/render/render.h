#pragma once

#include <string>
#include <render/shaders.h>
#include <render/renderObject.h>
#include <vector>
#include <memory>

// singleton
class Render final
{
	static Render* render;

	uint32_t vertexBuffer;

	std::vector<std::unique_ptr<ShaderProgram>> shaderPrograms;
	std::vector<std::unique_ptr<RenderObject>> renderObjects;

	Render();
	~Render();
	Render(const Render&) = delete;
	Render(const Render&&) = delete;
	Render& operator = (const Render&) = delete;
	Render& operator = (const Render&&) = delete;

public:

	static Render* makeRender();
	static void freeRender();

	void act(double deltaTime);
};
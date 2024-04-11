#pragma once

#include <string>
#include <render/shaderProgram.h>
#include <render/mesh.h>
#include <vector>
#include <memory>

// singleton
class Render final
{
	static Render* render;

	std::vector<ShaderProgram*> shaderPrograms;
	std::vector<BaseMesh*> meshes;

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
	void addMesh(BaseMesh* mesh);
};
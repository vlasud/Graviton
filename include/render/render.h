#pragma once

#include <string>
#include <render/shader.h>
#include <render/mesh.h>
#include <vector>
#include <memory>

struct Vertex
{
	glm::vec3 pos;
	glm::vec3 norm;
};

// singleton
class Render final
{
	static Render* render;

	std::vector<BaseMesh*> meshes;
	std::vector<Shader*> shaders;

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
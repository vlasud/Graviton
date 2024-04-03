#pragma once

#include <vector>
#include <glm/glm.hpp>


using vertex = glm::vec3;

class BaseMesh
{
	uint32_t VAO, VBO;
	std::vector<vertex> vertexArray;
	std::vector<uint32_t> VBOs;

	BaseMesh(const BaseMesh&) = delete;
	BaseMesh& operator = (const BaseMesh&) = delete;

public:

	BaseMesh();
	virtual ~BaseMesh();

	void draw();
};
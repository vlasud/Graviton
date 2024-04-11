#pragma once

#include <vector>
#include <glm/glm.hpp>


using vertex = glm::vec3;

class BaseMesh
{
	uint32_t VBO;
	std::vector<vertex> vertexArray;

	BaseMesh(const BaseMesh&) = delete;
	BaseMesh& operator = (const BaseMesh&) = delete;

public:

	BaseMesh(void *data, size_t length);
	virtual ~BaseMesh();

	virtual void draw();
};
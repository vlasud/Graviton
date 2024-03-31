#pragma once

#include <vector>
#include <glm/glm.hpp>


using vertex = glm::vec3;

class RenderObject
{
	std::vector<vertex> vertexArray;

public:

	RenderObject();
	virtual ~RenderObject();

};
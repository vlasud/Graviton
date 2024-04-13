#pragma once

#include <vector>
#include <glm/glm.hpp>
#include <string>


class BaseMesh
{
	uint32_t VAO;
	uint32_t VBO[2];
	
	void* vertexData;
	size_t vertexDataLen;

	void* colorData;
	size_t colorDataLen;

	BaseMesh(const BaseMesh&) = delete;
	BaseMesh& operator = (const BaseMesh&) = delete;

public:

	BaseMesh(const std::string& path_to_obj);
	virtual ~BaseMesh();

	virtual void draw();
};
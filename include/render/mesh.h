#pragma once

#include <vector>
#include <glm/glm.hpp>


using vertex = glm::vec3;

class BaseMesh
{
	uint32_t VBO, colorVBO, VAO;
	
	void* data;
	size_t dataLen;

	void* colorData;
	size_t colorDataLen;

	BaseMesh(const BaseMesh&) = delete;
	BaseMesh& operator = (const BaseMesh&) = delete;

public:

	BaseMesh(void *data, size_t length, void* color_data, size_t color_data_length);
	virtual ~BaseMesh();

	virtual void draw();
};
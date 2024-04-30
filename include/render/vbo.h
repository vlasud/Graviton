#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <vector>


template<typename T>
class VBO
{
	uint32_t id;

	VBO(const VBO&) = delete;
	VBO(VBO&&) = delete;
	VBO& operator = (const VBO&) = delete;
	VBO& operator = (VBO&&) = delete;

public:

	VBO(uint32_t type, const std::vector<T>& data_array)
	{
		glGenBuffers(1, &id);
		glBindBuffer(type, id);
		glBufferData(type, data_array.size() * sizeof(T), data_array.data(), GL_STATIC_DRAW);
	}

	~VBO()
	{
		glDeleteBuffers(1, &id);
	}

	__forceinline void setVertexAttribPointer(uint32_t pos, size_t size, uint32_t type, bool norm_data, uint32_t step, void* offset)
	{
		glVertexAttribPointer(pos, size, type, norm_data, step, offset);
	}
};
#include <render/mesh.h>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

BaseMesh::BaseMesh(void* data, size_t length, void *color_data, size_t color_data_length) :
	VBO(0), colorVBO(0), VAO(0), data(data), dataLen(length), colorData(color_data), colorDataLen(color_data_length)
{
	assert(data);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, dataLen * sizeof(float), data, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &colorVBO);
	glBindBuffer(GL_ARRAY_BUFFER, colorVBO);
	glBufferData(GL_ARRAY_BUFFER, colorDataLen * sizeof(float), colorData, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, nullptr);
	glEnableVertexAttribArray(1);
}

BaseMesh::~BaseMesh()
{
	glDeleteBuffers(1, &VBO);
}

void BaseMesh::draw()
{
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}
#include <render/mesh.h>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

BaseMesh::BaseMesh(void* data, size_t length) :
	VBO(0)
{
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, length * sizeof(float), data, GL_STATIC_DRAW);
}

BaseMesh::~BaseMesh()
{
	glDeleteBuffers(1, &VBO);
}

void BaseMesh::draw()
{
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
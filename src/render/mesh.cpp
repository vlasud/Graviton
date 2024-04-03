#include <render/mesh.h>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

BaseMesh::BaseMesh() :
	VAO(0), VBO(0)
{

	vertexArray = {
		vertex{0, 0, 0},
		vertex{0, 1, 0},
		vertex{1, 0, 0}
	};

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertexArray.size() * sizeof(vertexArray[0]), vertexArray.data(), GL_STATIC_DRAW);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}

BaseMesh::~BaseMesh()
{

}

void BaseMesh::draw()
{
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
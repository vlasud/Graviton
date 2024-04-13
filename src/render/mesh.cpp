#include <render/mesh.h>

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <cassert>
#include <render/objFile.h>

BaseMesh::BaseMesh(const std::string& path_to_obj)
{
	ObjFile *obj = new ObjFile(path_to_obj);
	
	delete obj;
	/*
	assert(data);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO[0]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	glBufferData(GL_ARRAY_BUFFER, vertexDataLen * sizeof(float), data, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &VBO[1]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	glBufferData(GL_ARRAY_BUFFER, colorDataLen * sizeof(float), colorData, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, nullptr);
	glEnableVertexAttribArray(1);*/
}

BaseMesh::~BaseMesh()
{
	glDeleteBuffers(1, &VBO[0]);
	glDeleteBuffers(1, &VBO[1]);
	glDeleteVertexArrays(1, &VAO);
}

void BaseMesh::draw()
{
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}
#include <render/mesh.h>

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <cassert>
#include <render/objFile.h>
#include <memory>


BaseMesh::BaseMesh(const std::string& path_to_obj) :
    transform(glm::mat4(1)), shouldDraw(true)
{
    auto obj = std::make_unique<ObjFile>(path_to_obj);

    vertexes = std::move(obj->v);
    vertexesTexturePos = std::move(obj->vt);
    indexes = std::move(obj->fv);

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    vertexVBO = std::make_unique<VBO<float>>(GL_ARRAY_BUFFER, vertexes);
    vertexVBO->setVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);

    indexVBO  = std::make_unique<VBO<uint32_t>>(GL_ELEMENT_ARRAY_BUFFER, indexes);

    glBindVertexArray(0);
}

BaseMesh::~BaseMesh()
{
    glDeleteVertexArrays(1, &VAO);
}

void BaseMesh::draw(double delta_time, uint32_t shader_program_id)
{
    transform = glm::rotate(transform, (float)delta_time * 0.1f, glm::vec3(0, 0.5, 0.5));

    GLuint transformLoc = glGetUniformLocation(shader_program_id, "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indexes.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void BaseMesh::setShouldDraw(bool value)
{
    shouldDraw = value;
}
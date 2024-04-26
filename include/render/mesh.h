#pragma once

#include <vector>
#include <glm/glm.hpp>
#include <string>


class BaseMesh
{
    uint32_t VAO;
    uint32_t VBO[3];
    
    std::vector<glm::vec3> vertexes;
    std::vector<uint32_t> indexes;
    std::vector<glm::vec4> colors;

    BaseMesh(const BaseMesh&) = delete;
    BaseMesh& operator = (const BaseMesh&) = delete;

public:

    BaseMesh(const std::string& path_to_obj);
    virtual ~BaseMesh();

    virtual void draw();
};
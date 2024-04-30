#pragma once

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <render/vbo.h>
#include <memory>

class BaseMesh
{

protected:
    uint32_t VAO;

    std::unique_ptr<VBO<float>> vertexVBO;
    std::unique_ptr<VBO<float>> colorVBO;
    std::unique_ptr<VBO<uint32_t>> indexVBO;

    std::vector<float> vertexes;
    std::vector<float> vertexesTexturePos;
    std::vector<float> colors;
    std::vector<uint32_t> indexes;

    glm::mat4 transform;
    bool shouldDraw;

    BaseMesh(const BaseMesh&) = delete;
    BaseMesh& operator = (const BaseMesh&) = delete;

public:

    BaseMesh(const std::string& path_to_obj);
    virtual ~BaseMesh();

    void setShouldDraw(bool value);
    bool isShouldDraw() const { return shouldDraw; };
    virtual void draw(double delta_time, uint32_t shader_program_id);
};
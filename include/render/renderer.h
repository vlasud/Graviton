#pragma once

#include <render/shader.h>
#include <render/mesh.h>
#include <vector>
#include <memory>


class Renderer final
{
    std::vector<std::unique_ptr<BaseMesh>> meshes;
    std::unique_ptr<Shader> meshShader;

    Renderer(const Renderer&) = delete;
    Renderer(Renderer&&) = delete;
    Renderer& operator = (const Renderer&) = delete;
    Renderer& operator = (Renderer&&) = delete;

    glm::mat4 view;
    glm::mat4 projection;

    void drawMesh(double delta_time);

public:

    Renderer(int width, int height);
    ~Renderer();

    void act(double delta_time);
    void addMesh(BaseMesh* mesh);
};
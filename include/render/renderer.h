#pragma once

#include <render/shader.h>
#include <render/mesh.h>
#include <vector>


class Renderer final
{
    std::vector<BaseMesh*> meshes;
    std::vector<Shader*> shaders;

    Renderer(const Renderer&) = delete;
    Renderer(Renderer&&) = delete;
    Renderer& operator = (const Renderer&) = delete;
    Renderer& operator = (Renderer&&) = delete;

public:

    Renderer();
    ~Renderer();

    void act(double deltaTime);
    void addMesh(BaseMesh* mesh);
};
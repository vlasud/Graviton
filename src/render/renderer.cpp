#include <render/renderer.h>
#include <render/shader.h>


Renderer::Renderer()
{
    shaders.push_back(new Shader("../../../graviton/shaders/test.glsl"));
    meshes.push_back(new BaseMesh("../../../assets/conus.obj"));
}

Renderer::~Renderer()
{
    for (auto& i : meshes)
        if (i)
            delete i;
    for (auto& i : shaders)
        if (i)
            delete i;
}

void Renderer::act(double deltaTime)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    for (auto& shader : shaders)
        shader->use();

    for (auto& mesh : meshes)
        mesh->draw();
}

void Renderer::addMesh(BaseMesh* mesh)
{
    if (!mesh)
        return;
}
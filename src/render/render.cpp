#include <render/render.h>
#include <render/shader.h>


Render* Render::render = nullptr;


Render::Render()
{
    shaders.push_back(new Shader("../graviton/shaders/test.glsl"));

    meshes.push_back(new BaseMesh("../assets/conus.obj"));
}

Render::~Render()
{
    for (auto& i : meshes)
        if (i)
            delete i;
    for (auto& i : shaders)
        if (i)
            delete i;
}

Render* Render::makeRender()
{
    if (!render)
        render = new Render();
    return render;
}

void Render::freeRender()
{
    if (render)
        delete render;
}

void Render::act(double deltaTime)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (auto& shader : shaders)
        shader->use();

    for (auto& mesh : meshes)
        mesh->draw();
}

void Render::addMesh(BaseMesh* mesh)
{
    if (!mesh)
        return;
}
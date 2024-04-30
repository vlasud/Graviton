#include <render/renderer.h>
#include <render/shader.h>


Renderer::Renderer() :
    view(glm::mat4(1))
{
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -1.0f));

    meshes.push_back(std::make_unique<BaseMesh>("../assets/duck.obj"));
    meshes.push_back(std::make_unique<BaseMesh>("../assets/fish.obj"));

    meshShader = std::make_unique<Shader>(std::vector<std::string>{
        "../graviton/shaders/test.glsl"
    });
}

Renderer::~Renderer()
{
}

void Renderer::act(double delta_time)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    drawMesh(delta_time);
}

void Renderer::addMesh(BaseMesh* mesh)
{
    if (!mesh)
        return;
}

void Renderer::drawMesh(double delta_time)
{
    meshShader->use();

    GLuint viewLoc = glGetUniformLocation(meshShader->getProgramId(), "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

    for (auto& mesh : meshes)
    {
        if (mesh->isShouldDraw())
            mesh->draw(delta_time, meshShader->getProgramId());
    }
}
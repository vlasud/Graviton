#include <render/render.h>

#include <glad/gl.h>

static inline void prepare_render()
{
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void engine_render_act(double deltaTime)
{
    prepare_render();
}
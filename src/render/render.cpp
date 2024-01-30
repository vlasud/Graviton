#include <render/render.h>

#include <glad/gl.h>

static void prepare_render()
{
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void render::render_act()
{
    prepare_render();

    glBegin(GL_LINES);
    glVertex2f(10, 10);
    glVertex2f(20, 20);
    glEnd();
}
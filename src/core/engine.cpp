#include <core/engine.h>

#include <render/render.h>
#include <input/input.h>

#include <chrono>


Engine* Engine::engine = nullptr;


static inline double calc_delta_time()
{
    static std::chrono::high_resolution_clock deltaTimeTimer;
    static auto prevTime = deltaTimeTimer.now();
    auto curTime = deltaTimeTimer.now();
    double deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(curTime - prevTime).count() / 1000.0;
    prevTime = curTime;
    return deltaTime;
}

Engine* Engine::makeEngine()
{
    if (!engine)
        engine = new Engine();
    return engine;
}

void Engine::freeEngine()
{
    if (engine)
    {
        delete engine;
        engine = nullptr;
    }
}

Engine::Engine() :
    window(nullptr), scene(nullptr), render(nullptr)
{
}

Engine::~Engine()
{
    glfwDestroyWindow(window);
    glfwTerminate();

    if (scene)
        delete scene;
    if (render)
        Render::freeRender();
}

void Engine::run()
{
    if (!scene || !render)
        return;

    if (!window)
    {
        // TODO: handle
        return;
    }

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        double deltaTime = calc_delta_time();

        scene->act(deltaTime);
        render->act(deltaTime);

        glfwSwapBuffers(window);
    }
    
}

bool Engine::initEngine()
{
    if (!glfwInit())
        return false;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(windowSettings.size[0], windowSettings.size[1],
        windowSettings.title.c_str(), NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1, 1, -1, 1, 1, 1);
    glMatrixMode(GL_MODELVIEW);
    glOrtho(-width, width, height, -height, -1.0f, 1.0f);

    scene = new Scene();
    if (!scene)
    {
        // TODO: handle
        return false;
    }

    render = Render::makeRender();
    if (!render)
    {
        // TODO: handle
        return false;
    }

    return true;
}
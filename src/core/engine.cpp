#include <core/engine.h>

#include <render/renderer.h>
#include <input/input.h>

#include <chrono>
#include <iostream>
#include <functional>


static void window_resize_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}


Engine* Engine::get()
{
    static Engine* engine = nullptr;
    if (!engine)
        engine = new Engine;
    return engine;
}

Engine::Engine() :
    window(nullptr)
{
}

Engine::~Engine()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Engine::run()
{
    if (!window || !scene.get() || !renderer.get())
    {
        // TODO: handle
        return;
    }

    static double prevTime = glfwGetTime();
    static double curTime = glfwGetTime();

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        curTime = glfwGetTime();
        double deltaTime = curTime - prevTime;
        prevTime = curTime;

        scene->act(deltaTime);
        renderer->act(deltaTime);

        glfwSwapBuffers(window);
    }
}

bool Engine::initEngine(const EngineInitDesc& init_desc)
{
    if (!glfwInit())
        return false;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(init_desc.windowSize[0], init_desc.windowSize[1],
        init_desc.title.c_str(), NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return false;
    }

    glfwSetWindowSizeCallback(window, window_resize_callback);

    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);

    glEnable(GL_DEPTH_TEST);

    scene = std::make_unique<Scene>();
    if (!scene.get())
    {
        // TODO: handle
        return false;
    }

    renderer = std::make_unique<Renderer>(init_desc.windowSize[0], init_desc.windowSize[1]);
    if (!renderer.get())
    {
        // TODO: handle
        return false;
    }

    GLenum error = glGetError();
    if (error != GL_NO_ERROR)
        std::cout << "OpenGL error: " << error << std::endl;

    return true;
}
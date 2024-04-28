#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <core/scene.h>
#include <render/renderer.h>
#include <string>
#include <memory>


// singleton
class Engine final
{
    static Engine* engine;

    struct WindowSettings
    {
        uint32_t size[2] = { 640, 480 };
        std::string title = "Engine";
    } windowSettings;

    GLFWwindow *window;
    std::unique_ptr<Scene> scene;
    std::unique_ptr<Renderer> renderer;

    Engine();
    Engine(const Engine&) = delete;
    Engine(Engine&&) = delete;
    ~Engine();
    Engine& operator = (const Engine&) = delete;
    Engine& operator = (Engine&&) = delete;

public:

    static Engine* makeEngine();
    static void freeEngine();

    void run();
    bool initEngine();
};
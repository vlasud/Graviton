#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <core/scene.h>
#include <render/renderer.h>
#include <string>
#include <memory>


struct EngineInitDesc
{
    uint32_t windowSize[2];
    std::string title;
};

// Meyers singleton
class Engine final
{
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

    static Engine* get();

    void run();
    bool initEngine(const EngineInitDesc &init_desc);
};
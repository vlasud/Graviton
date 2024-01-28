#include <render/render.h>

#include <GLFW/glfw3.h>

static int windowSize[2] = { 640, 480 };
static const char* windowTitle = "Simple 3d shooter";

int WinMain()
{
    GLFWwindow* window;

    if (!glfwInit())
        return 1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    window = glfwCreateWindow(windowSize[0], windowSize[1], windowTitle, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return 1;
    }

    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

	return 0;
}
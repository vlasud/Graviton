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
		delete engine;
}

Engine::Engine() :
	window(nullptr), scene(nullptr), render(nullptr)
{
	if (!glfwInit())
		return;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	window = glfwCreateWindow(windowSettings.size[0], windowSettings.size[1],
		windowSettings.title.c_str(), NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window);
	gladLoadGL(glfwGetProcAddress);

	scene = new Scene();
	if (!scene)
	{
		// TODO: handle
		return;
	}

	render = Render::makeRender();
	if (!render)
	{
		// TODO: handle
		return;
	}
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
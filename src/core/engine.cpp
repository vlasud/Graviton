#include <core/engine.h>

#include <render/render.h>
#include <input/input.h>
#include <core/sceneManager.h>

#include <chrono>


GLFWwindow* window;


static inline double calc_delta_time()
{
	static std::chrono::high_resolution_clock deltaTimeTimer;
	static auto prevTime = deltaTimeTimer.now();
	auto curTime = deltaTimeTimer.now();

	double deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(curTime - prevTime).count() / 1000.0;

	prevTime = curTime;

	return deltaTime;
}

static void engine_act()
{
	double deltaTime = calc_delta_time();

	engine_input_act(deltaTime);
	engine_scene_act(deltaTime);
	engine_render_act(deltaTime);
}

int init_engine(const InitEngineArgs args)
{
	if (!glfwInit())
		return 1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	window = glfwCreateWindow(
		args.windowSize[0],
		args.windowSize[1],
		args.title,
		NULL,
		NULL);

	if (!window)
	{
		glfwTerminate();
		return 1;
	}

	engine_input_init(window);
	//engine_load_scene(args.sceneName);

	glfwMakeContextCurrent(window);
	gladLoadGL(glfwGetProcAddress);
	
	return 0;
}

void run_engine()
{
	if (!window)
		return;

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		engine_act();

		glfwSwapBuffers(window);
	}

	stop_engine();
}

void stop_engine()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}
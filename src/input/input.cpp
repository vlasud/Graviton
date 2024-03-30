#include <input/input.h>
#include <vector>


std::vector<InputAction> inputActions;


void engine_input_init(GLFWwindow* window)
{
	glfwSetKeyCallback(window, engine_input_callback);

	inputActions.reserve(10);
}


void engine_input_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	//inputActions.push_back(InputAction{ key, action });
}


void engine_input_act(double deltaTime)
{

	inputActions.clear();
}
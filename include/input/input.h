#pragma once

#include <GLFW/glfw3.h>


void engine_input_init(GLFWwindow* window);
void engine_input_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void engine_input_act(double deltaTime);

struct InputAction
{
	int keyCode;
	int action;
};
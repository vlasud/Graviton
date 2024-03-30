#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <string>


struct InitEngineArgs
{
	uint32_t windowSize[2] = {640, 480};
	const char* title = "None";
	std::string sceneName;
};

int init_engine(const InitEngineArgs args);
void run_engine();
void stop_engine();
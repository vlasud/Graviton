#include <core/sceneManager.h>

#include <fstream>
#include <cassert>


Scene* currentScene = nullptr;


void engine_load_scene(const std::string &scene_name)
{
	std::ifstream stream(scene_name);

	assert(stream.is_open());

	stream.close();
}

void engine_scene_act(double deltaTime)
{
	if (!currentScene)
		return;

	currentScene->act(deltaTime);
}
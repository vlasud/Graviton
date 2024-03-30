#include <core/sceneManager.h>

#include <fstream>
#include <cassert>


void engine_load_scene(const std::string &scene_name)
{
	std::ifstream stream(scene_name);

	assert(stream.is_open());

	stream.close();
}
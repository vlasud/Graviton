#pragma once

#include <string>
#include <core/scene.h>


void engine_load_scene(const std::string& scene_name);
void engine_scene_act(double deltaTime);
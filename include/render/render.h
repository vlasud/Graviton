#pragma once

#include <string>

#include <render/shaders.h>

void engine_render_act(double deltaTime);
void engine_load_shaders(const std::string& shaders_path);
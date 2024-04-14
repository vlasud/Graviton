#pragma once

#include <render/render.h>
#include <string>
#include <vector>

struct ObjFile
{
	std::vector<glm::vec3> vertexes;
	std::vector<uint32_t> indexes;

	ObjFile(const std::string &path_to_file);
	~ObjFile();
};
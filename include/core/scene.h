#pragma once

#include <string>

class Scene final
{
	std::string name;

	Scene(const Scene&) = delete;
	Scene(const Scene&&) = delete;

	Scene& operator = (const Scene&) = delete;
	Scene& operator = (const Scene&&) = delete;

public:

	Scene() = default;
	~Scene();
};
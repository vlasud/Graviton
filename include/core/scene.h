#pragma once

#include <core/object.h>

#include <string>
#include <vector>

class Scene final
{
	Scene(const Scene&) = delete;
	Scene(const Scene&&) = delete;

	Scene& operator = (const Scene&) = delete;
	Scene& operator = (const Scene&&) = delete;

	std::string name;
	std::vector<Object> objectsPool;

public:

	Scene() = default;
	~Scene();

	void act(double deltaTime);
};
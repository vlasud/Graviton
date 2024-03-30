#include <core/scene.h>

Scene::~Scene()
{

}

void Scene::act(double deltaTime)
{
	for (auto& i : objectsPool)
	{
		i.update(deltaTime);
	}
}
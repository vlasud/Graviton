#include <core/object.h>

#include <vector>

std::vector<Object> objectsPool;

void engine_objects_act(double deltaTime)
{
	for (auto& i : objectsPool)
	{
		i.update(deltaTime);
	}
}

void add_object()
{

}
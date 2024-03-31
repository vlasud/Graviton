#include <core/engine.h>


int WinMain()
{
	Engine* engine = Engine::makeEngine();
	if (!engine)
		return 1;

	engine->run(); // game loop inside

	Engine::freeEngine();

	return 0;
}
#include <render/render.h>
#include <render/shaders.h>


Render* Render::render = nullptr;


Render::Render()
{
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
}

Render::~Render()
{
}

Render* Render::makeRender()
{
	if (!render)
		render = new Render();
	return render;
}

void Render::freeRender()
{
	if (render)
		delete render;
}

void Render::act(double deltaTime)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);


	for (auto& shaderProgram : shaderPrograms)
	{
		if (shaderProgram)
			shaderProgram->use();
	}
}
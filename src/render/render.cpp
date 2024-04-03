#include <render/render.h>
#include <render/shaders.h>


Render* Render::render = nullptr;


Render::Render()
{
	meshes.push_back(std::make_unique<BaseMesh>());
	
	auto shaderP = std::make_unique<ShaderProgram>();
	shaderP->addShader("shaders/test.frag");
	shaderP->addShader("shaders/test.vert");
	shaderP->link();

	shaderPrograms.push_back(std::move(shaderP));
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

	for (auto& mesh : meshes)
	{
		mesh->draw();
	}
}
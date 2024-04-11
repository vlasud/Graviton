#include <render/render.h>
#include <render/shader.h>


Render* Render::render = nullptr;


Render::Render()
{
	// pos attribute
	glEnableVertexAttribArray(0);
	// color attribute
	glEnableVertexAttribArray(1);

	auto shaderP = new ShaderProgram();
	shaderP->addShader("shaders/test.frag");
	shaderP->addShader("shaders/test.vert");
	shaderP->link();

	shaderPrograms.push_back(shaderP);
}

Render::~Render()
{
	for (auto& i : shaderPrograms)
		if (i)
			delete i;

	for (auto& i : meshes)
		if (i)
			delete i;
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

void Render::addMesh(BaseMesh* mesh)
{
	if (!mesh)
		return;

	float vertex[6] = {
		-0.5f,  0.5f,
		 0.0f,  0.5f,
		 0.5f, -0.5f
	};

	meshes.push_back(new BaseMesh((void*)vertex, 6));
}
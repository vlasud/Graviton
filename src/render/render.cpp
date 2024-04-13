#include <render/render.h>
#include <render/shader.h>


Render* Render::render = nullptr;


Render::Render()
{
	shaders.push_back(new Shader("../../../shaders/test.glsl"));
	//shaders.push_back(new Shader("shaders/test_a.glsl"));

	float a[6] = {
		-0.5f,  0.5f,
		 0.0f,  0.5f,
		 0.5f, -0.5f
	};

	float color_a[12] = {
		-0.5f,  0.5f, -0.5f,  1,
		 0.0f,  0.5f, -0.5f,  1,
		 0.5f, -0.5f, - 0.5f,  1,
	};

	meshes.push_back(new BaseMesh((void*)a, 6, (void*)color_a, 12));

	float b[6] = {
		-1.0,   -1.0f,
		 1.0f,  2.0f,
		 2.0f,  -2.0f
	};

	float color_b[12] = {
		-0.5f,  0.5f, -0.5f,  1,
		 0.0f,  0.5f, -0.5f,  1,
		 0.5f, -0.5f, -0.5f,  1,
	};

	meshes.push_back(new BaseMesh((void*)b, 6, (void*)color_b, 12));
}

Render::~Render()
{
	for (auto& i : meshes)
		if (i)
			delete i;
	for (auto& i : shaders)
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

	for (auto& shader : shaders)
		shader->use();

	for (auto& mesh : meshes)
		mesh->draw();
}

void Render::addMesh(BaseMesh* mesh)
{
	if (!mesh)
		return;
}
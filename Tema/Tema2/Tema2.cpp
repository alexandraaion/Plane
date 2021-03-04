#include "Tema2.h"

#include <vector>
#include <string>
#include <iostream>
#include "Transform3D.h"

#include <Core/Engine.h>

using namespace std;
float coordY;
float angularStep;
int up = 0;
int down = 0;
float start;
float norAng;
float mareAng;
float combustibil;

Tema2::Tema2()
{
}

Tema2::~Tema2()
{
}

void Tema2::Init()
{
	{
		Mesh* mesh = new Mesh("avion");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "avion.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("elice");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "elice.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("mare");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "mare3.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("box");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "box.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("teapot");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "teapot.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("sphere");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "sphere.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("life");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "life.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	// Create a shader program for drawing face polygon with the color of the normal
	{
		Shader* shader = new Shader("ShaderLab7");
		shader->AddShader("Source/Tema/Tema2/Shaders/VertexShader.glsl", GL_VERTEX_SHADER);
		shader->AddShader("Source/Tema/Tema2/Shaders/FragmentShader.glsl", GL_FRAGMENT_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}


	//Light & material properties

	lightPosition = glm::vec3(0, 1, 1);
	materialShininess = 30;
	materialKd = 0.5;
	materialKs = 0.5;
	radians = 0;
	coordY = 0;
	angularStep = 0;
	start = -1.2;
	norAng = 0;
	mareAng = 0;
	combustibil = 0;

}

void Tema2::FrameStart()
{
	glClearColor(0.49, 0.73, 0.91, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	glViewport(0, 0, resolution.x, resolution.y);
	glm::ivec2 mousePosition;
	mousePosition = window->GetCursorPosition();

	float mouseBefore = mousePosition[1];
}

void Tema2::Update(float deltaTimeSeconds)
{
	radians += deltaTimeSeconds * 0.5f;
	norAng += deltaTimeSeconds * 0.8f;
	mareAng += deltaTimeSeconds;
	

	if (up == 1) {
		coordY += deltaTimeSeconds *1.5f;
		up = 0;
		if (angularStep < 0.5) {
			angularStep += deltaTimeSeconds * 0.5f;
		}
	}

	if (down == 1) {
		coordY -= deltaTimeSeconds *1.5f;
		down = 0;
		if (angularStep > -0.5) {
			angularStep -= deltaTimeSeconds * 0.5f;
		}
	}

	glm::ivec2 resolution = window->GetResolution();
	/////////////////////////////////////////////////////////////////////////////////////////NORUL1
	{ 
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng*0.5);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(2.2, 0.3, 0.2);
		modelMatrix *= Transform3D::RotateOZ(0.3);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		RenderSimpleMesh(meshes["box"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0.02f, 0.06f, 0.74f));
	}
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng*0.5);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(2.1, 0.35, 0.2);
		modelMatrix *= Transform3D::RotateOX(0.2);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		RenderSimpleMesh(meshes["box"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0.02f, 0.06f, 0.74f));
	}
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng*0.5);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(2, 0.30, 0.2);
		modelMatrix *= Transform3D::RotateOZ(0.15);
		modelMatrix *= Transform3D::RotateOX(norAng*3);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		RenderSimpleMesh(meshes["box"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0.02f, 0.06f, 0.74f));
	}
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng*0.5);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(1.9, 0.25, 0.2);
		modelMatrix *= Transform3D::RotateOY(0.11);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		RenderSimpleMesh(meshes["box"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0.02f, 0.06f, 0.74f));
	}

	/////////////////////////////////////////////////////////////////////////////////////NORUL2
	{ 
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng * 0.5 + 1.2);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(2.2, 0.4, 0.2);
		modelMatrix *= Transform3D::RotateOY(0.3);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		RenderSimpleMesh(meshes["box"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0.02f, 0.06f, 0.74f));
	}
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng * 0.5 + 1.2);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(2.1, 0.4, 0.2);
		modelMatrix *= Transform3D::RotateOX(0.2);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		RenderSimpleMesh(meshes["box"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0.02f, 0.06f, 0.74f));
	}
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng * 0.5 + 1.2);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(2, 0.25, 0.2);
		modelMatrix *= Transform3D::RotateOZ(0.15);
		modelMatrix *= Transform3D::RotateOX(norAng*3);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		RenderSimpleMesh(meshes["box"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0.02f, 0.06f, 0.74f));
	}
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng * 0.5 + 1.2);
		modelMatrix *= Transform3D::Translate(0.1, 0.28, -2);
		modelMatrix *= Transform3D::Translate(1.9, 0.35, 0.2);
		modelMatrix *= Transform3D::RotateOY(0.11);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		RenderSimpleMesh(meshes["box"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0.02f, 0.06f, 0.74f));
	}

	////////////////////////////////////////////////////////////////////////////////////////NORUL3
	{ 
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng * 0.5 + 2.5);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(2.2, 0.2, 0.2);
		modelMatrix *= Transform3D::RotateOY(0.3);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		RenderSimpleMesh(meshes["box"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0.02f, 0.06f, 0.74f));
	}
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng * 0.5 + 2.5);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(2, 0.3, 0.2);
		modelMatrix *= Transform3D::RotateOX(0.2);
		modelMatrix *= Transform3D::RotateOX(norAng * 3);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		RenderSimpleMesh(meshes["box"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0.02f, 0.06f, 0.74f));
	}
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng * 0.5 + 2.5);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(1.9, 0.2, 0.2);
		modelMatrix *= Transform3D::RotateOZ(0.15);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		RenderSimpleMesh(meshes["box"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0.02f, 0.06f, 0.74f));
	}

	////////////////////////////////////////////////////////////////////////////////////////////////NORUL4
	{ 
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng * 0.5 + 3.5);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(2.2, 0.45, 0.2);
		modelMatrix *= Transform3D::RotateOY(0.3);
		modelMatrix *= Transform3D::RotateOX(norAng * 3);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		RenderSimpleMesh(meshes["box"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0.02f, 0.06f, 0.74f));
	}
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng * 0.5 + 3.5);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(2.1, 0.45, 0.2);
		modelMatrix *= Transform3D::RotateOX(0.2);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		RenderSimpleMesh(meshes["box"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0.02f, 0.06f, 0.74f));
	}
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng * 0.5 + 3.5);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(2, 0.48, 0.2);
		modelMatrix *= Transform3D::RotateOZ(0.15);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		RenderSimpleMesh(meshes["box"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0.02f, 0.06f, 0.74f));
	}
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng * 0.5 + 3.5);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(1.9, 0.42, 0.2);
		modelMatrix *= Transform3D::RotateOY(0.11);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		RenderSimpleMesh(meshes["box"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0.02f, 0.06f, 0.74f));
	}

	///////////////////////////////////////////////////////////////////////////////////////////////NORUL5
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng * 0.5 + 4.8);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(2.2, 0.2, 0.2);
		modelMatrix *= Transform3D::RotateOY(0.3);
		modelMatrix *= Transform3D::RotateOX(norAng * 3);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		RenderSimpleMesh(meshes["box"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0.02f, 0.06f, 0.74f));
	}
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng * 0.5 + 4.8);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(2, 0.3, 0.2);
		modelMatrix *= Transform3D::RotateOX(0.2);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		RenderSimpleMesh(meshes["box"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0.02f, 0.06f, 0.74f));
	}
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng * 0.5 + 4.8);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(1.9, 0.2, 0.2);
		modelMatrix *= Transform3D::RotateOZ(0.15);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		RenderSimpleMesh(meshes["box"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0.02f, 0.06f, 0.74f));
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////AVION
	{ 
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, coordY, 0);
		modelMatrix *= Transform3D::RotateOZ(angularStep);
		modelMatrix *= Transform3D::Translate(-1, 1.3f, 0);
		modelMatrix *= Transform3D::Scale(0.08f, 0.08f, 0.08f);
		RenderSimpleMesh(meshes["avion"], shaders["ShaderLab7"], modelMatrix, glm::vec3(1.00f, 0.00f, 0.17f));
	}

	{ //elice
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, coordY, 0);
		modelMatrix *= Transform3D::RotateOZ(angularStep);
		modelMatrix *= Transform3D::Translate(-0.68f, 1.3f, 0);
		modelMatrix *= Transform3D::RotateOX(radians);
		modelMatrix *= Transform3D::Scale(0.01f, 0.02f, 0.02f);
		RenderSimpleMesh(meshes["elice"], shaders["ShaderLab7"], modelMatrix, glm::vec3(1.00f, 0.00f, 0.17f));
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////MAREA
	{ 
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::RotateOZ(mareAng);
		modelMatrix *= Transform3D::Translate(0, 0, 2);
		modelMatrix *= Transform3D::RotateOY(-1.57f);
		modelMatrix *= Transform3D::Scale(1.5f, 0.9f, 0.9f);
		RenderSimpleMesh(meshes["mare"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0.1f, 0.5f, 0.9f));
	}

	//////////////////////////////////////////////////////////////////////////////////COMBUSTIBIL1
	{ 
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng * 0.5 + 0.6);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(2, 0.25, 0.2);
		modelMatrix *= Transform3D::RotateOY(radians*3);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		//modelMatrix *= Transform3D::Scale(2, 2, 2);
		RenderSimpleMesh(meshes["teapot"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0, 1, 1));
	}
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng * 0.5 + 0.6);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(2.1, 0.3, 0.2);
		modelMatrix *= Transform3D::RotateOY(radians*3);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		RenderSimpleMesh(meshes["teapot"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0, 1, 1));
	}
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng * 0.5 + 0.6);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(2.2, 0.25, 0.2);
		modelMatrix *= Transform3D::RotateOY(radians*3);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		RenderSimpleMesh(meshes["teapot"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0, 1, 1));
	}
	//////////////////////////////////////////////////////////////////////////////////COMBUSTIBIL2
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng * 0.5 + 3.2);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(2, 0.25, 0.2);
		modelMatrix *= Transform3D::RotateOY(radians * 3);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		//modelMatrix *= Transform3D::Scale(2, 2, 2);
		RenderSimpleMesh(meshes["teapot"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0, 1, 1));
	}
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng * 0.5 + 3.2);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(2.1, 0.3, 0.2);
		modelMatrix *= Transform3D::RotateOY(radians * 3);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		RenderSimpleMesh(meshes["teapot"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0, 1, 1));
	}
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng * 0.5 + 3.2);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(2.2, 0.25, 0.2);
		modelMatrix *= Transform3D::RotateOY(radians * 3);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		RenderSimpleMesh(meshes["teapot"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0, 1, 1));
	}

	//////////////////////////////////////////////////////////////////////////////////////OBSTACOL1
	{ 
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng * 0.5 + 4.2);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(2, 0.4, 0.2);
		modelMatrix *= Transform3D::RotateOY(radians * 3);
		modelMatrix *= Transform3D::Scale(0.15f, 0.15f, 0.15f);
		RenderSimpleMesh(meshes["sphere"], shaders["ShaderLab7"], modelMatrix, glm::vec3(1, 0, 0));
	}

	//////////////////////////////////////////////////////////////////////////////////////OBSTACOL2
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng * 0.5 + 1.7);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(1, 1, 0.2);
		modelMatrix *= Transform3D::RotateOY(radians * 3);
		modelMatrix *= Transform3D::Scale(0.15f, 0.15f, 0.15f);
		RenderSimpleMesh(meshes["sphere"], shaders["ShaderLab7"], modelMatrix, glm::vec3(1, 0, 0));
	}

	//////////////////////////////////////////////////////////////////////////////////////OBSTACOL3
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng * 0.5 + 2.7);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(1.7, 0.7, 0.2);
		modelMatrix *= Transform3D::RotateOY(radians * 3);
		modelMatrix *= Transform3D::Scale(0.15f, 0.15f, 0.15f);
		RenderSimpleMesh(meshes["sphere"], shaders["ShaderLab7"], modelMatrix, glm::vec3(1, 0, 0));
	}

	//////////////////////////////////////////////////////////////////////////////////////OBSTACOL4
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-0.1, -0.3, 2);
		modelMatrix *= Transform3D::RotateOZ(mareAng * 0.5 + 5.2);
		modelMatrix *= Transform3D::Translate(0.1, 0.3, -2);
		modelMatrix *= Transform3D::Translate(1.5, 0.7, 0.2);
		modelMatrix *= Transform3D::RotateOY(radians * 3);
		modelMatrix *= Transform3D::Scale(0.15f, 0.15f, 0.15f);
		RenderSimpleMesh(meshes["sphere"], shaders["ShaderLab7"], modelMatrix, glm::vec3(1, 0, 0));
	}

	//////////////////////////////////////////////////////////////////////////////////////OBSTACOL5
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(start, 1, 0.2);
		modelMatrix *= Transform3D::RotateOY(radians * 2);
		modelMatrix *= Transform3D::Scale(0.15f, 0.15f, 0.15f);
		RenderSimpleMesh(meshes["sphere"], shaders["ShaderLab7"], modelMatrix, glm::vec3(1, 0, 0));
	}

	///////////////////////////////////////////////////////////////////////////////////////VIETI
	{ 
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-2.2, 2.1, 0);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		RenderSimpleMesh(meshes["life"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0, 1, 0));
	}
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-2.1, 2.1, 0);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		RenderSimpleMesh(meshes["life"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0, 1, 0));
	}
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-2, 2.1, 0);
		modelMatrix *= Transform3D::Scale(0.1f, 0.1f, 0.1f);
		RenderSimpleMesh(meshes["life"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0, 1, 0));
	}
	//////////////////////////////////////////////////////////////////////////////////////BARA COMBUSTIBIL

	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(1.8f, 2.2f, 0);

		modelMatrix *= Transform3D::Scale(0.9f, 0.1f, 0.01f);

		RenderSimpleMesh(meshes["box"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0.7, 0.9, 1));
	}
	{
		glm::mat4 modelMatrix = glm::mat4(1);


		modelMatrix *= Transform3D::Translate(1.75f + (combustibil) * 0.5f, 2.17f, 0.1f);

		modelMatrix *= Transform3D::Scale(0.8f - combustibil, 0.08f, 0.01f);
		RenderSimpleMesh(meshes["box"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0, 1, 0));
	}
	if (combustibil < 0.8) {
		combustibil += deltaTimeSeconds * 0.03;
	}
	else {
		exit(1);
	}


	if (start < -3) {
		start = 3;
	}
	else {
		start -= deltaTimeSeconds;
	}


}

void Tema2::FrameEnd()
{
}

void Tema2::RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, const glm::vec3& color)
{
	if (!mesh || !shader || !shader->GetProgramID())
		return;

	// render an object using the specified shader and the specified position
	glUseProgram(shader->program);

	// Set shader uniforms for light & material properties



	// TODO: Set light position uniform

	int location = glGetUniformLocation(shader->GetProgramID(), "light_position");
	glUniform3fv(location, 1, glm::value_ptr(lightPosition));

	// TODO: Set eye position (camera position) uniform
	glm::vec3 eyePosition = GetSceneCamera()->transform->GetWorldPosition();
	location = glGetUniformLocation(shader->GetProgramID(), "eye_position");
	glUniform3fv(location, 1, glm::value_ptr(eyePosition));


	// TODO: Set material property uniforms (shininess, kd, ks, object color) 
	location = glGetUniformLocation(shader->GetProgramID(), "material_shininess");
	glUniform1i(location, materialShininess);
	location = glGetUniformLocation(shader->GetProgramID(), "material_kd");
	glUniform1f(location, materialKd);
	location = glGetUniformLocation(shader->GetProgramID(), "material_ks");
	glUniform1f(location, materialKs);
	location = glGetUniformLocation(shader->GetProgramID(), "object_color");
	glUniform3fv(location, 1, glm::value_ptr(color));

	// Bind model matrix
	GLint loc_model_matrix = glGetUniformLocation(shader->program, "Model");
	glUniformMatrix4fv(loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	// Bind view matrix
	glm::mat4 viewMatrix = GetSceneCamera()->GetViewMatrix();
	int loc_view_matrix = glGetUniformLocation(shader->program, "View");
	glUniformMatrix4fv(loc_view_matrix, 1, GL_FALSE, glm::value_ptr(viewMatrix));

	// Bind projection matrix
	glm::mat4 projectionMatrix = GetSceneCamera()->GetProjectionMatrix();
	int loc_projection_matrix = glGetUniformLocation(shader->program, "Projection");
	glUniformMatrix4fv(loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

	// Draw the object
	glBindVertexArray(mesh->GetBuffers()->VAO);
	glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_SHORT, 0);
}


void Tema2::OnInputUpdate(float deltaTime, int mods)
{
	float speed = 2;

	if (!window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
	{
		glm::vec3 up = glm::vec3(0, 1, 0);
		glm::vec3 right = GetSceneCamera()->transform->GetLocalOXVector();
		glm::vec3 forward = GetSceneCamera()->transform->GetLocalOZVector();
		forward = glm::normalize(glm::vec3(forward.x, 0, forward.z));

		// Control light position using on W, A, S, D, E, Q
		if (window->KeyHold(GLFW_KEY_W)) lightPosition -= forward * deltaTime * speed;
		if (window->KeyHold(GLFW_KEY_A)) lightPosition -= right * deltaTime * speed;
		if (window->KeyHold(GLFW_KEY_S)) lightPosition += forward * deltaTime * speed;
		if (window->KeyHold(GLFW_KEY_D)) lightPosition += right * deltaTime * speed;
		if (window->KeyHold(GLFW_KEY_E)) lightPosition += up * deltaTime * speed;
		if (window->KeyHold(GLFW_KEY_Q)) lightPosition -= up * deltaTime * speed;
	}
}

void Tema2::OnKeyPress(int key, int mods)
{
	// add key press event
}

void Tema2::OnKeyRelease(int key, int mods)
{
	// add key release event
}

void Tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
	glm::ivec2 mousePosition;
	mousePosition = window->GetCursorPosition();

	float mouseOY = mousePosition[1];

	if (mouseOY < mouseBefore) {
		up = 1;
	}
	else if (mouseOY > mouseBefore) {
		down = 1;
	}

	mouseBefore = mouseOY;
}

void Tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
}

void Tema2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Tema2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema2::OnWindowResize(int width, int height)
{
}
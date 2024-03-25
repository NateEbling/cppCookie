#include "core.h"
#include "scenes/LevelEditorScene.h"

namespace Cookie
{
	GLuint vaoID, vboID, eboID;

	void LevelEditorScene::init()
	{
		loadResources();

		camera = new Camera(glm::vec2(-250, 0));

		defaultShader = new Shader("assets/shaders/default.glsl");
		defaultShader->compile();

	}
	
	// TODO: LevelEditorScene::loadResources
	void LevelEditorScene::loadResources()
	{

	}

	// TODO: LevelEditorScene::update
	void LevelEditorScene::update(float dt)
	{

	}

	// TODO: LevelEditorScene::imgui
	void LevelEditorScene::imgui()
	{

	}
}
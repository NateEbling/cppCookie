#include "core.h"
#include "scenes/LevelEditorScene.h"

namespace Cookie
{
	GLuint vaoID, vboID, eboID;
	//GameObject levelEditorComp = GameObject("LevelEditor", Transform(glm::vec2()), 0);

	void LevelEditorScene::init()
	{
		loadResources();

		camera = new Camera(glm::vec2(-250, 0));

		defaultShader = new Shader("assets/shaders/default.glsl");
		defaultShader->compile();

		if (levelLoaded)
		{
			/*if (gameObjects.empty())
			{
				activeGameObject = gameObjects[0];
			}
			return;*/
		}
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
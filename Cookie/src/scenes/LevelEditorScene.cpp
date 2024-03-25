#include "core.h"
#include "scenes/LevelEditorScene.h"

namespace Cookie
{
	void LevelEditorScene::init()
	{
		loadResources();

		camera = new Camera(glm::vec2(-250, 0));
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
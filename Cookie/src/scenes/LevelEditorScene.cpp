#include "core.h"
#include "scenes/LevelEditorScene.h"

namespace Cookie
{
	namespace Editor
	{
		LevelEditorScene::LevelEditorScene()
		{
			this->levelEditorComp = new Entity("LevelEditor", new Transform(glm::vec2()), 0);
		}

		void LevelEditorScene::init()
		{
			this->camera = new Camera(glm::vec2(-250, 0));

			loadResources();
		}

		void LevelEditorScene::loadResources()
		{

		}

		void LevelEditorScene::update(float dt)
		{

		}

		void LevelEditorScene::render()
		{

		}

		void LevelEditorScene::imgui()
		{

		}


	}
}
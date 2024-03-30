#ifndef LEVEL_EDITOR_SCENE_H
#define LEVEL_EDITOR_SCENE_H

#include "core.h"
#include "Scene.h"

namespace Cookie
{
	namespace Editor
	{
		class LevelEditorScene : Scene
		{
		private:
			Entity* levelEditorComp;
			void loadResources();
		public:
			LevelEditorScene();
			void init() override;
			void update(float dt) override;
			void render() override;
			void imgui() override;
		};
	}
}

#endif

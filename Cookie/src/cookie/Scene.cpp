#include "core.h"
#include "cookie/Scene.h"

namespace Cookie
{
	namespace Scene
	{
		static SceneType currentScene = SceneType::None;
		static SceneType nextSceneType = SceneType::None;
		static bool changeSceneAtFrameEnd = false;

		void init(SceneType type)
		{

		}

		void update(float dt)
		{
			
		}
	}
}
#include "core.h"
#include "cookie/Scene.h"
#include "renderer/Shader.h"

namespace Cookie
{
	namespace Scene
	{
		static SceneType currentScene = SceneType::None;
		static SceneType nextSceneType = SceneType::None;
		static bool changeSceneAtFrameEnd = false;
		Shader* defaultShader;

		void init(SceneType type)
		{
			defaultShader = new Shader();
			defaultShader->compile("assets/shaders/default.glsl");
		}

		void update(float dt)
		{
			defaultShader->bind();

			defaultShader->unbind();
		}
	}
}
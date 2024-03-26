#pragma once
#include "core.h"
#include "Scene.h"
#include "renderer/Shader.h"
#include "core/GameObject.h"

namespace Cookie
{
	class LevelEditorScene : Scene
	{
	private:
		GameObject* obj1;
		//Spritesheet sprites;
		//SpriteRender obj1Sprite;
		GameObject levelEditorComp;
		void loadResources();
		Shader* defaultShader;
	public:
		void init() override;
		void update(float dt) override;
		void imgui() override;
	};
}

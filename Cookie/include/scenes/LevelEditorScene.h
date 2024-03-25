#pragma once
#include "core.h"
#include "Scene.h"

namespace Cookie
{
	class LevelEditorScene : Scene
	{
	private:
		//GameObject obj1;
		//Spritesheet sprites;
		//SpriteRender obj1Sprite;
		//GameObject levelEditorComp = new GameObject("LevelEditor", new Transform(new Vector2f()), 0);
		void loadResources();
	public:
		void init() override;
		void update(float dt) override;
		void imgui() override;

	};
}

#pragma once
#include "core.h"

namespace Cookie
{
	enum class SceneType : uint8
	{
		None,
		Level,
		LevelEditor
	};


	namespace Scene
	{
		void init(SceneType type);
		void start();
		void load();
		// void addGameObjectToScene(GameObject go);
		void update(float dt);
		void changeScene(SceneType type);
		// Camera camera();
		void saveExit();
		void free();
	}
}

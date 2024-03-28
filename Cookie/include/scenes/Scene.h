#ifndef SCENE_H
#define SCENE_H

#include "core.h"
#include "core/GameObject.h"
#include "core/Camera.h"

namespace Cookie
{
	class Scene
	{
	private:
		bool isRunning;
	protected:
		bool levelLoaded;
		std::vector<GameObject*> gameObjects;
		GameObject* activeGameObject;
		Camera* camera;
	public:
		Scene();
		void addGameObjectToScene(GameObject* go);
		GameObject* getGameObject(int gameObjectId);
		void init();
		virtual void start();
		virtual void update(float dt);
		virtual void render();
		virtual void imgui();
		Camera* getCamera() { return this->camera; }
		void saveExit();
		void load();
	};
}
#endif

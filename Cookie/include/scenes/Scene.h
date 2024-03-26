   #pragma once
#include "core.h"
#include "core/Camera.h"
#include "core/GameObject.h"

namespace Cookie
{
	class Scene
	{
	protected:
		// Renderer renderer
		Camera* camera;
		std::vector<GameObject> gameObjects; 
		GameObject activeGameObject;
		bool levelLoaded;
	private:
		bool isRunning;
	public:
		virtual void init();
		virtual void start();
		virtual void update(float dt);
		virtual void imgui();
		void addGameObjectToScene(GameObject go);
		void saveExit();
		void sceneImgui();
		Camera* getCamera() { return camera; }
		void load();
	};
}

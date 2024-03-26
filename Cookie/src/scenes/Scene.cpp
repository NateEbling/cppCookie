#include "core.h"
#include "scenes/Scene.h"

namespace Cookie
{
	void Scene::init()
	{

	}

	// TODO: Scene::start
	void Scene::start()
	{
		for (GameObject go : gameObjects)
		{
			go.start();
			// renderer
		}
		isRunning = true;
	}

	// TODO: Scene:addGameObjectToScene
	void Scene::addGameObjectToScene(GameObject go)
	{
		if (!isRunning)
		{
			gameObjects.push_back(go);
		}
		else
		{
			gameObjects.push_back(go);
			go.start();
			// renderer
		}
	}
	
	void Scene::update(float dt)
	{

	}

	// TODO: Scene::sceneImgui
	void Scene::sceneImgui()
	{

	}

	void Scene::imgui()
	{

	}

	// TODO: Scene::saveExit
	void Scene::saveExit()
	{

	}

	// TODO: Scene::load
	void Scene::load()
	{

	}
}
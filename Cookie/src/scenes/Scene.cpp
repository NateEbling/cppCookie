#include "core.h"
#include "scenes/Scene.h"

namespace Cookie
{
	Scene::Scene()
	{
		this->isRunning = false;
		this->gameObjects = std::vector<GameObject*>();
		this->activeGameObject = nullptr;
		this->levelLoaded = false;
		this->camera = nullptr;
	}

	void Scene::init()
	{

	}

	void Scene::start()
	{
		for (GameObject* go : gameObjects)
		{
			go->start();
			// Renderer
		}
		isRunning = true;
	}

	void Scene::addGameObjectToScene(GameObject* go)
	{
		if (!isRunning)
		{
			gameObjects.push_back(go);
			go->start();
			// Renderer
		}
	}

	// TODO: Scene:getGameObject (based on id)
	GameObject* Scene::getGameObject(int gameObjectId)
	{
		return nullptr;
	}

	void Scene::update(float dt)
	{

	}

	void Scene::render()
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
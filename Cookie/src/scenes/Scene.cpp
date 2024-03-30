#include "core.h"
#include "scenes/Scene.h"

namespace Cookie
{
	Scene::Scene()
	{
		this->isRunning = false;
		this->entities = std::vector<Entity*>();
		this->activeEntity = nullptr;
		this->levelLoaded = false;
		this->camera = nullptr;
	}

	void Scene::init()
	{

	}

	void Scene::start()
	{
		for (Entity* go : entities)
		{
			go->start();
			// Renderer
		}
		isRunning = true;
	}

	void Scene::addEntityToScene(Entity* go)
	{
		if (!isRunning)
		{
			entities.push_back(go);
			go->start();
			// Renderer
		}
	}

	// TODO: Scene:getGameObject (based on id)
	Entity* Scene::getEntity(int entityId)
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
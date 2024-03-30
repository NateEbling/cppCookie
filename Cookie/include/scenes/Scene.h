#ifndef SCENE_H
#define SCENE_H

#include "core.h"
#include "ecs/Entity.h"
#include "cameras/Camera.h"

namespace Cookie
{
	class Scene
	{
	private:
		bool isRunning;
	protected:
		bool levelLoaded;
		std::vector<Entity*> entities;
		Entity* activeEntity;
		Camera* camera;
	public:
		Scene();
		void addEntityToScene(Entity* go);
		Entity* getEntity(int entityId);
		virtual void init();
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

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "core.h"
#include "components/Component.h"
#include "core/Transform.h"

namespace Cookie
{
	class GameObject
	{
	private:
		static int ID_COUNTER;
		int uid;
		char* name;
		std::vector<Component*> components;
		int zIndex;
	public:
		Transform transform;
		GameObject(char* name, Transform transform, int zIndex);
		// TODO: GameObject::getComponent
		//Component getComponent(Component componentClass); // not sure how to make this work in C++
		void removeComponent(Component* c);
		void addComponent(Component* c);
		void update(float dt);
		void start();
		void imgui();
		int getzIndex() { return this->zIndex; }
		static void init(int maxId) { ID_COUNTER = maxId; }
		int getUid() { return this->uid; }
		std::vector<Component*> getAllComponents() { return this->components; }
	};
}

#endif

#include "core.h"
#include "ecs/Entity.h"

namespace Cookie
{
	int Entity::ID_COUNTER = 0;

	Entity::Entity(char* name, Transform* transform, int zIndex)
		:name(name),
		transform(transform),
		zIndex(zIndex)
	{
		this->components = std::vector<Component*>();
		this->uid = ID_COUNTER++;
	}

	// TODO: workaround for GameObject::removeComponent
	void Entity::removeComponent(Component* c)
	{

	}

	void Entity::addComponent(Component* c)
	{
		c->generateId();
		this->components.push_back(c);
		//c.gameObject = this;
	}

	void Entity::update(float dt)
	{
		for (int i = 0; i < components.size(); i++)
		{
			components[i]->update(dt);
		}
	}

	void Entity::start()
	{
		for (int i = 0; i < components.size(); i++)
		{
			components[i]->start();
		}
	}

	void Entity::imgui()
	{
		for (int i = 0; i < components.size(); i++)
		{
			components[i]->imgui();
		}
	}
}
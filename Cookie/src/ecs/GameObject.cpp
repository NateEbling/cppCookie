#include "core.h"
#include "ecs/GameObject.h"

namespace Cookie
{
	int GameObject::ID_COUNTER = 0;

	GameObject::GameObject(char* name, Transform* transform, int zIndex)
		:name(name),
		transform(transform),
		zIndex(zIndex)
	{
		this->components = std::vector<Component*>();
		this->uid = ID_COUNTER++;
	}

	// TODO: workaround for GameObject::removeComponent
	void GameObject::removeComponent(Component* c)
	{

	}

	void GameObject::addComponent(Component* c)
	{
		c->generateId();
		this->components.push_back(c);
		//c.gameObject = this;
	}

	void GameObject::update(float dt)
	{
		for (int i = 0; i < components.size(); i++)
		{
			components[i]->update(dt);
		}
	}

	void GameObject::start()
	{
		for (int i = 0; i < components.size(); i++)
		{
			components[i]->start();
		}
	}

	void GameObject::imgui()
	{
		for (int i = 0; i < components.size(); i++)
		{
			components[i]->imgui();
		}
	}
}
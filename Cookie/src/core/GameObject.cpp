#include "core.h"
#include "core/GameObject.h"

namespace Cookie
{
	GameObject::GameObject(const char* n, Transform t, int zInd)
		:name(n),
		transform(t),
		zIndex(zInd)
	{
	}

	template<typename T> T GameObject::getComponent(T componentClass)
	{
		for (Component c : components)
		{
			// TODO: this needs to work for derived classes also
			if (typeid(componentClass).name() == typeid(c).name())
			{
				return componentClass;
			}
		}
		return nullptr;
	}

	template<typename T> T GameObject::removeComponent(T componentClass)
	{
		for (int i = 0; i < components.size(); i++)
		{
			Component c = components[i];
			if (typeid(componentClass).name() == typeid(c).name)
			{
				components.remove(i);
				return;
			}
		}
	}

	void GameObject::addComponent(Component c)
	{
		c.generateId();
		components.push_back(c);
		c.gameObject = this;
	}

	void GameObject::update(float dt)
	{
		for (int i = 0; i < components.size(); i++)
		{
			components[i].update(dt);
		}
	}

	void GameObject::start()
	{
		for (int i = 0; i < components.size(); i++)
		{
			components[i].start();
		}
	}
	
	void GameObject::imgui()
	{
		for (Component c : components)
		{
			c.imgui();
		}
	}

	void GameObject::init(int maxId)
	{
		ID_COUNTER = maxId;
	}
}
#include "core.h"
#include "cookie/GameObject.h"

namespace Cookie
{
	GameObject::GameObject(const char* name)
	{
		this->name = name;
		this->components = std::list<Component>();
		this->transform = Transform();
		this->zIndex = 0;
	}

	GameObject::GameObject(const char* name, Transform transform, int zIndex)
	{
		this->name = name;
		this->components = std::list<Component>();
		this->transform = transform;
		this->zIndex = zIndex;
	}

	template<typename T> T getComponent(T component)
	{
		for (Component c : components)
		{
			// We want to check if the passed in component is the same type as component c
			// How can we check for derived classes?
			if (typeid(component).name() == typeid(c).name())
			{

			}
		}
	}
}
#include "core.h"
#include "core/GameObject.h"

namespace Cookie
{
	int GameObject::ID_COUNTER = 0;

	GameObject::GameObject(char* name, Transform transform, int zIndex)
		:name(name),
		transform(transform),
		zIndex(zIndex)
	{
		this->components = std::list<Component>();
		this->uid = ID_COUNTER++;
	}

	// TODO: workaround for GameObject::removeComponent
	void GameObject::removeComponent(Component c)
	{

	}

	void GameObject::addComponent(Component c)
	{
		//c.generateId();

	}
}
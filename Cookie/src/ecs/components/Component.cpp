#include "core.h"
#include "ecs/components/Component.h"

namespace Cookie
{
	int Component::ID_COUNTER = 0;

	Component::Component()
	{
		this->uid = -1;
	}

	void Component::start()
	{

	}

	void Component::update(float dt)
	{

	}

	// TODO: Component::imgui
	void Component::imgui()
	{

	}

	void Component::generateId()
	{
		if (this->uid == -1)
		{
			this->uid = ID_COUNTER++;
		}
	}
}
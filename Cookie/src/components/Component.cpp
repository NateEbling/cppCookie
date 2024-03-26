#include "core.h"
#include "components/Component.h"

namespace Cookie
{
	void Component::start()
	{

	}

	void Component::update(float dt)
	{

	}

	// TODO: Component::imgui (serialization)
	void Component::imgui()
	{
		
	}

	int Component::getUid()
	{
		if (uid == -1)
		{
			uid = ID_COUNTER++;
		}
	}

	void Component::init(int maxId)
	{
		ID_COUNTER = maxId;
	}
}
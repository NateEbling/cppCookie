#include "core.h"
#include "core/Transform.h"

namespace Cookie
{
	Transform::Transform()
	{
		init(glm::vec2(), glm::vec2());
	}

	Transform::Transform(glm::vec2 position)
	{
		init(position, glm::vec2());
	}

	Transform::Transform(glm::vec2 position, glm::vec2 scale)
	{
		init(position, scale);
	}

	void Transform::init(glm::vec2 pos, glm::vec2 sc)
	{
		position = pos;
		scale = sc;
	}

	Transform Transform::copy()
	{
		Transform t = Transform(position, scale);
		return t;
	}

	void Transform::copy(Transform t)
	{
		position = t.position;
		scale = t.scale;
	}

	// TODO: Transform::equals
	bool Transform::equals(void* obj)
	{
		return false;
	}
}
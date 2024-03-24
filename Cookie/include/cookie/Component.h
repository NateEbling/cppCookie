#pragma once
#include "core.h"
#include "cookie/GameObject.h"

namespace Cookie
{
	class Component
	{
	public:
		virtual void start();
		virtual void update(float dt);
		virtual void imgui();
		GameObject* gameObject;
	};
}

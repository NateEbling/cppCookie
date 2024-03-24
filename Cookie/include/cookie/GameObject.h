#pragma once
#include "core.h"
#include "cookie/Transform.h"
#include "cookie/Component.h"

namespace Cookie
{
	class GameObject
	{
	public:
		std::list<Component> components;
		const char* name;
		Transform transform;
		int zIndex;
		GameObject(const char* name);
		GameObject(const char* name, Transform transform, int zIndex);
		template<typename T> T getComponent(T component);
		template<typename T> T removeComponent(T component);
		void addComponent(Component c);
		void update(float dt);
		void start();
		void imgui();
		int getzIndex();
	};
}

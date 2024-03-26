#pragma once
#include "core.h"
#include "components/Component.h"
#include "core/Transform.h"

namespace Cookie
{
	class GameObject
	{
	private:
		static int ID_COUNTER;
		int uid;
		const char* name;
		std::vector<Component> components;
		int zIndex;
	public:
		Transform transform;
		GameObject(const char* name, Transform transform, int zIndex);
		template<typename T> T getComponent(T component);
		template<typename T> T removeComponent(T componentClass);
		void addComponent(Component c);
		void update(float dt);
		void start();
		void imgui();
		int getzIndex() { return zIndex; }
		static void init(int maxId);
		int getUid() { return uid; }
		std::vector<Component> getAllComponents() { return components; }
	};
}

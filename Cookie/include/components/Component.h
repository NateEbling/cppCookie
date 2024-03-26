#pragma once
#include "core.h"
#include "core/GameObject.h"

namespace Cookie
{
	class Component
	{
	private:
		static int ID_COUNTER;
		int uid;

	public:
		GameObject* gameObject;
		virtual void start();
		virtual void update(float dt);
		void imgui();
		void generateId();
		int getUid() { return uid; }
		static void init(int maxId);
	};
}

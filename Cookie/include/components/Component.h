#pragma once
#include "core.h"

namespace Cookie
{
	class Component
	{
	private:
		static int ID_COUNTER;
		int uid;
		Component();
	public:
		void start();
		void update(float dt);
		void imgui();
		void generateId();
		int getUid() { return this->uid; }
		static void init(int maxId) { ID_COUNTER = maxId; }
	};
}

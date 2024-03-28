#ifndef COMPONENT_H
#define COMPONENT_H

#include "core.h"
//#include "core/GameObject.h" // this causes many errors even though header guards are in place

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
		virtual void imgui();
		virtual void generateId();
		int getUid() { return this->uid; }
		static void init(int maxId) { ID_COUNTER = maxId; }
	};
}

#endif

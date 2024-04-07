#pragma once

#include "Definitions.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Cookie
{
	class Window
	{
	public:
		static void init();
		static void tick();
		static void shutdown();

		static void setSize(const U32 width, const U32 height);
		static U32 getWidth();
		static U32 getHeight();

		static void* getHandle();
	};
}

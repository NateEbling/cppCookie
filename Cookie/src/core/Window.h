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
	};
}

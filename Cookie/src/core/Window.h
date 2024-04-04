#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Cookie
{
	struct Window
	{
		const float r, g, b, a;
		const char* title;
		I32 width, height;


	};
}

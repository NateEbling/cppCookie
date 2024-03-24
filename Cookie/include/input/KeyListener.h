#pragma once
#include "core.h"

namespace Cookie
{
	class KeyListener
	{
	public:
		KeyListener* get();
		static void keyCallback(GLFWwindow* glfwWindow, int key, int scancode, int action, int mods);
		static bool isKeyPressed(int keycode);
	private:
		static KeyListener* instance;
		bool keyPressed[GLFW_KEY_LAST];
		KeyListener();
		
	};
}

#pragma once
#include "core.h"

namespace Cookie
{
	class KeyListener
	{
	public:
		KeyListener* get();
		void keyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods);
		bool isKeyPressed(int keyCode);
	private:
		KeyListener* instance;
		bool keyPressed[GLFW_KEY_LAST];
	};
}

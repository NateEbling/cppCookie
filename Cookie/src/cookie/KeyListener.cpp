#include "core.h"
#include "cookie/KeyListener.h"

namespace Cookie
{
	KeyListener* KeyListener::get()
	{
		if (instance == nullptr)
		{
			instance = new KeyListener();
		}
		return instance;
	}

	void KeyListener::keyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods)
	{
		if (action == GLFW_PRESS)
		{
			keyPressed[key] = true;
		}
		else if (action == GLFW_RELEASE)
		{
			keyPressed[key] = false;
		}
	}

	bool KeyListener::isKeyPressed(int keyCode)
	{
		return keyPressed[keyCode];
	}
}
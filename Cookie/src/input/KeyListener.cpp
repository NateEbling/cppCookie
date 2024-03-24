#include "core.h"
#include "input/KeyListener.h"

namespace Cookie
{
	KeyListener* KeyListener::instance;

	KeyListener::KeyListener()
	{
		
	}

	KeyListener* KeyListener::get()
	{
		if (instance == nullptr)
		{
			instance = new KeyListener();
		}

		return instance;
	}

	void KeyListener::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (action == GLFW_PRESS)
		{
			instance->keyPressed[key] = true;
		}
	}

	bool KeyListener::isKeyPressed(int keycode)
	{
		return instance->keyPressed[keycode];
	}
}
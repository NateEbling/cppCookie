#include "core.h"
#include "input/listeners/KeyListener.h"

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

	// TODO: keyCallback
	void KeyListener::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
	
	}

	// TODO isKeyPressed
	bool KeyListener::isKeyPressed(int keycode)
	{
		return false;
	}
}
#include "core.h"
#include "input/listeners/MouseListener.h"

namespace Cookie
{
	MouseListener* MouseListener::instance;

	MouseListener::MouseListener()
	{
		xPos = 0.0;
		yPos = 0.0;
		lastX = 0.0;
		lastY = 0.0;
		scrollX = 0.0;
		scrollY = 0.0;
	}

	MouseListener* MouseListener::get()
	{
		if (instance == nullptr)
		{
			instance = new MouseListener();
		}

		return instance;
	}

	// TODO: mousePosCallback
	void MouseListener::mousePosCallback(GLFWwindow* window, double xpos, double ypos)
	{
		
	}

	// TODO: mouseButtonCallback
	void MouseListener::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		
	}

	// TODO: mouseScrollCallback
	void MouseListener::mouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
	{
		
	}

	// TODO: endFrame
	void MouseListener::endFrame()
	{
	
	}

	// TODO: getOrthoX
	float MouseListener::getOrthoX()
	{
		return 0.0f;
	}

	// TODO: getOrthoY
	float MouseListener::getOrthoY()
	{
		return 0.0f;
	}
}
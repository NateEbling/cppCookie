#include "core.h"
#include "cookie/MouseListener.h"

namespace Cookie
{
	MouseListener::MouseListener()
	{
		scrollX = 0.0;
		scrollY = 0.0;
		xPos = 0.0;
		yPos = 0.0;
		lastX = 0.0;
		lastY = 0.0;
		mouseButtonPressed[GLFW_MOUSE_BUTTON_LAST] = {};
		dragging = false;
	}

	MouseListener* MouseListener::get()
	{
		if (instance == nullptr) {
			instance = new MouseListener();
		}
		return instance;
	}

	void MouseListener::mousePosCallback(GLFWwindow* window, double xpos, double ypos)
	{
		lastX = getX();
		lastY = getY();
		xPos = xpos;
		yPos = ypos;
		dragging = mouseButtonPressed[0] || mouseButtonPressed[1];
	}
	
	void MouseListener::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		if (action == GLFW_PRESS)
		{
			mouseButtonPressed[button] = true;
		}
		else if (action == GLFW_RELEASE)
		{
			mouseButtonPressed[button] = false;
			dragging = false;
		}
	}

	void MouseListener::mouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset)
	{
		scrollX = xOffset;
		scrollY = yOffset;
	}

	void MouseListener::endFrame()
	{
		scrollX = 0;
		scrollY = 0;
		lastX = getX();
		lastY = getY();
	}

	float MouseListener::getX()
	{
		return (float)xPos;
	}

	float MouseListener::getY()
	{
		return (float)yPos;
	}

	float MouseListener::getDx()
	{
		return (float)(lastX - xPos);
	}

	float MouseListener::getDy()
	{
		return (float)(lastY - yPos);
	}

	float MouseListener::getScrollX()
	{
		return (float)scrollX;
	}

	float MouseListener::getScrollY()
	{
		return (float)scrollY;
	}

	bool MouseListener::isDragging()
	{
		return dragging;
	}

	bool MouseListener::mouseButtonDown(int button)
	{
		return mouseButtonPressed[button];
	}
}
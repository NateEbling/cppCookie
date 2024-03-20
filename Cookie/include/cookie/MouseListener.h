#pragma once
#include "core.h"

namespace Cookie
{
	class MouseListener
	{
	public:
		MouseListener* get();
		void mousePosCallback(GLFWwindow* window, double xPos, double yPos);
		void mouseButtonCallback(GLFWwindow*, int button, int action, int mods);
		void mouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset);
		void endFrame();
		float getX();
		float getY();
		float getDx();
		float getDy();
		float getScrollX();
		float getScrollY();
		bool isDragging();
		bool mouseButtonDown(int button);
	private:
		MouseListener* instance;
		double scrollX, scrollY;
		double xPos, yPos, lastX, lastY;
		bool mouseButtonPressed[GLFW_MOUSE_BUTTON_LAST];
		bool dragging;
		MouseListener();
		~MouseListener();
	};
}

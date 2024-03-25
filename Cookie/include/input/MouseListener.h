#pragma once
#include "core.h"

namespace Cookie
{
	class MouseListener
	{
	private:
		static MouseListener* instance;
		double scrollX, scrollY;
		double xPos, yPos, lastX, lastY;
		bool mouseButtonPressed[GLFW_MOUSE_BUTTON_LAST];
		bool isDragging;
		glm::vec2 gameViewportPos;
		glm::vec2 gameViewportSize;
		MouseListener();
	public:
		static MouseListener* get();
		static void mousePosCallback(GLFWwindow* window, double xpos, double ypos);
		static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		static void mouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
		static void endFrame();
		float getX() { return (float)xPos; }
		float getY() { return (float)yPos; }
		static float getOrthoX();
		static float getOrthoY();
		float getDx() { return (float)(lastX - xPos); }
		float getDy() { return (float)(lastY - yPos); }
		float getScrollX() { return (float)scrollX; }
		float getScrollY() { return (float)scrollY; }
		bool isMouseDragging() { return isDragging; }
		bool mouseButtonDown(int button) { return mouseButtonPressed[button] = true; }
		void setGameViewportPos(glm::vec2 gViewportPos) { gameViewportPos = gViewportPos; }
		void setGameViewportSize(glm::vec2 gViewportSize) { gameViewportSize = gViewportSize; }
	};
}

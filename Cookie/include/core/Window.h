#pragma once

#include "core.h"

namespace Cookie
{
	class Window
	{
	private:
		int width, height;
		const char* title;
		GLFWwindow* glfwWindow;
		// ImGuiLayer imguiLayer;
		// Framebuffer framebuffer;
		float r, g, b, a;
		// static Scene currentScene;
		Window();

		static void changeScene(int newScene);

	public:
		//static Scene getScene();
		static GLFWwindow& getWindow();
		void run();
		void init();
		void loop();
		static int getWidth();
		static int getHeight();
		static void setWidth(int newWidth);
		static void setHeight(int newHeight);
		//static Framebuffer getFramebuffer();
		static float getTargetAspectRatio();
	};
}

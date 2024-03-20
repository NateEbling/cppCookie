#pragma once
#include "core.h"

namespace Cookie
{
	class Window
	{
	public:
		GLFWwindow* getGLFWwindow();
		void getScene();
		void init();
		void run();
		void loop();
		void destroy();
		bool shouldClose();
		bool setVSync();
		float getAspectRatio();
		static int getWidth();
		static int getHeight();
		static int setWidth(int newWidth);
		static int setHeight(int newHeight);
		static void changeScene(int newScene);
		static void free();
	private:
		int width, height;
		const char* title;
		GLFWwindow* glfwWindow;
		// ImGuiLayer imGuiLayer;
		// static Scene currentScene;
		static Window window;
		float r, g, b, a;
		Window() {}

	};
}

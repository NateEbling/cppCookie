#ifndef WINDOW_H
#define WINDOW_H

#include "core.h"

namespace Cookie
{
	class Window
	{
	private:
		int width, height;
		const char* title;
		static void* windowPtr;
		// ImGuiLayer imguiLayer;
		// Framebuffer framebuffer;
		float r, g, b, a;
		// static Scene currentScene;
		static void changeScene(int newScene);
		static Window* window;
	public:
		Window();
		//static Scene getScene();
		static Window* getWindow();
		void run();
		void init();
		void loop();
		int getWidth() const { return width; }
		int getHeight() const { return height; }
		void setWidth(int newWidth);
		void setHeight(int newHeight);
		//static Framebuffer getFramebuffer();
		static float getTargetAspectRatio();
	};
}

#endif

#include "core.h"
#include "cookie/Window.h"

namespace Cookie 
{
	Window::Window()
	{
		width = 1920;
		height = 1080;
		title = "My Game";
		r = 1;
		g = 1;
		b = 1;
		a = 1;
	}

	Window::~Window()
	{

	}

	void Window::changeScene(int newScene)
	{
		switch (newScene)
		{
		case 0:
			// Level editor scene
			break;
		case 1:
			// Level scene
			break;
		default:
			std::cerr << "Unknown scene" << std::endl;
		}

		// currentScene.load();
		// currentScene.init();
		// currentScene.start();
	}

	GLFWwindow* Window::getGLFWwindow()
	{
		return glfwWindow;
	}

	void Window::run()
	{

	}

	void Window::init()
	{
		if (!glfwInit())
		{
			std::cerr << "Unable to initialize GLFW" << std::endl;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		glfwWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);

		if (glfwWindow == nullptr)
		{
			glfwTerminate();
			std::cerr << "Failed to create GLFW window" << std::endl;
		}

		// Callbacks
		//glfwSetCursorPosCallback(glfwWindow, )

	}


}
#include "core.h"
#include "cookie/Window.h"

namespace Cookie 
{
	Window::Window()
	{
		this->width = 1920;
		this->height = 1080;
		this->title = "My Game";
		this->r = 1;
		this->g = 1;
		this->b = 1;
		this->a = 1;
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
			std::cout << "Unknown scene" << std::endl;
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
			std::cout << "Unable to initialize GLFW" << std::endl;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	}


}
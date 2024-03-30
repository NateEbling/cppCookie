#include "core.h"
#include "graphics/Window.h"
#include "input/listeners/MouseListener.h"
#include "input/listeners/KeyListener.h"

namespace Cookie
{
	void* Window::windowPtr = nullptr;
	Window* Window::window = nullptr;

	Window::Window()
	{
		width = 1920;
		height = 1080;
		title = "Cookie";
		r = 1;
		g = 1;
		b = 1;
		a = 1;
	}

	// TODO: add changeScene method
	static void changeScene(int newScene)
	{

	}

	Window* Window::getWindow()
	{
		if (window == nullptr)
		{
			window = new Window();
		}

		return window;
	}

	void Window::init()
	{
		if (!glfwInit())
		{
			std::cerr << "Unable to initialize GLFW" << std::endl;
		}

		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		//window->windowPtr = (void*)glfwCreateWindow(width, height, title, glfwGetPrimaryMonitor(), NULL); // Use this long term to removed window decorations
		window->windowPtr = (void*)glfwCreateWindow(width, height, title, NULL, NULL);

		if (window->windowPtr == nullptr)
		{
			glfwTerminate();
			std::cerr << "Failed to create GLFW window" << std::endl;
		}

		// Callbacks
		glfwSetCursorPosCallback((GLFWwindow*)window->windowPtr, MouseListener::mousePosCallback);
		glfwSetMouseButtonCallback((GLFWwindow*)window->windowPtr, MouseListener::mouseButtonCallback);
		glfwSetScrollCallback((GLFWwindow*)window->windowPtr, MouseListener::mouseScrollCallback);
		glfwSetKeyCallback((GLFWwindow*)window->windowPtr, KeyListener::keyCallback);

		// Make OpenGL context current
		glfwMakeContextCurrent((GLFWwindow*)window->windowPtr);
		gladLoadGL();

		// Enable vsync
		glfwSwapInterval(1);

		glfwShowWindow((GLFWwindow*)window->windowPtr);

		// TODO: add changeScene(defaultScene)

	}

	void Window::loop()
	{
		float beginTime = (float)glfwGetTime();
		float endTime;
		float dt = -1.0f;

		while (!glfwWindowShouldClose((GLFWwindow*)windowPtr))
		{
			glfwPollEvents();

			glClearColor(r, g, b, a);
			glClear(GL_COLOR_BUFFER_BIT);

			glfwSwapBuffers((GLFWwindow*)windowPtr);
		}
	}

	void Window::run()
	{
		init();
		loop();

		// Free memory
		glfwDestroyWindow((GLFWwindow*)windowPtr);
		glfwTerminate();
		glfwSetErrorCallback(NULL);
	}

	void Window::setWidth(int newWidth)
	{
		width = newWidth;
	}

	void Window::setHeight(int newHeight)
	{
		height = newHeight;
	}

	// TODO: add getTargetAspectRatio
	float Window::getTargetAspectRatio()
	{
		return 16.0f / 9.0f;
	}
}
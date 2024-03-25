#include "core.h"
#include "core/Window.h"
#include "input/MouseListener.h"
#include "input/KeyListener.h"

namespace Cookie
{
	void* Window::windowPtr;

	Window::Window()
	{
		width = 1920;
		height = 1080;
		title = "Cookie";
		r = 1;
		g = 1;
		b = 1;
		a = 1;
		windowPtr = nullptr;
	}

	// TODO: add changeScene method
	static void changeScene(int newScene)
	{

	}

	void Window::init()
	{
		Window* win = new Window();

		if (!glfwInit())
		{
			std::cerr << "Unable to initialize GLFW" << std::endl;
		}

		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		win->windowPtr = (void*)glfwCreateWindow(width, height, title, nullptr, nullptr);

		if (win->windowPtr == nullptr)
		{
			glfwTerminate();
			std::cerr << "Failed to create GLFW window" << std::endl;
		}

		// Callbacks
		glfwSetCursorPosCallback((GLFWwindow*)win->windowPtr, MouseListener::mousePosCallback);
		glfwSetMouseButtonCallback((GLFWwindow*)win->windowPtr, MouseListener::mouseButtonCallback);
		glfwSetScrollCallback((GLFWwindow*)win->windowPtr, MouseListener::mouseScrollCallback);
		glfwSetKeyCallback((GLFWwindow*)win->windowPtr, KeyListener::keyCallback);

		// Make OpenGL context current
		glfwMakeContextCurrent((GLFWwindow*)win->windowPtr);
		gladLoadGL();

		// Enable vsync
		glfwSwapInterval(1);

		glfwShowWindow((GLFWwindow*)win->windowPtr);

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
}
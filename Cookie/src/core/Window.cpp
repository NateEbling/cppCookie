#include "Window.h"
#include "Definitions.h"

using namespace std;

namespace Cookie
{
	namespace
	{
		float r = 1;
		float g = 1;
		float b = 1;
		float a = 1;
		std::string title;
		U32 width = 1920;
		U32 height = 1080;
		GLFWwindow* window = nullptr;
	}

	void Window::init()
	{
		if (!glfwInit())
		{
			CK_ASSERT("Could not initialize GLFW");
		}

		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		title = "Cookie " + to_string(ck_info::version_major) + "." + to_string(ck_info::version_minor) + "." + to_string(ck_info::version_revision);
		window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

		if (window == nullptr)
		{
			glfwTerminate();
			CK_ASSERT("Failed to create window");
		}

		
		glfwMakeContextCurrent(window);
		gladLoadGL(); // This is needed, otherwise will crash

		glfwSwapInterval(1);

		glfwShowWindow(window);
	}

	void Window::tick()
	{
		while (!glfwWindowShouldClose(window))
		{
			glfwPollEvents();

			glClearColor(r, g, b, a);
			glClear(GL_COLOR_BUFFER_BIT);

			glfwSwapBuffers(window);
		}
	}

	void Window::shutdown()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		glfwSetErrorCallback(nullptr);
		window = nullptr;
	}

	void Window::setSize(const U32 newWidth, const U32 newHeight)
	{
		width = newWidth;
		height = newHeight;
		glfwSetWindowSize(window, width, height);
	}

	U32 Window::getWidth()
	{
		return width;
	}

	U32 Window::getHeight()
	{
		return height;
	}

	void* Window::getHandle()
	{
		return window;
	}
}
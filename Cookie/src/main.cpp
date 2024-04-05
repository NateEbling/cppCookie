#include "Core/Window.h"

using namespace Cookie;

int main()
{
	Window::init();
	Window::tick();
	Window::shutdown();

	return 0;
}
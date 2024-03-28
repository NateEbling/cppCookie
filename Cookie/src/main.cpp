#include "core.h"
#include "core/Window.h"

using namespace Cookie;

int main()
{
	Window* window = Window::getWindow();
	window->run();

	return 0;
}
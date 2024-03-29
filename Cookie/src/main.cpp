#include "core.h"
#include "core/Window.h"

using namespace Cookie;

int main()
{
#ifdef _DEBUG
	std::cout << "DEBUG MODE" << std::endl;
#endif
	Window* window = Window::getWindow();
	window->run();

	return 0;
}
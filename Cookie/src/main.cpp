#include "core.h"
#include "cookie/Window.h"

using namespace Cookie;


int main()
{
	Window* window = new Window();
	window->run();

	window->free();
	return 0;
}
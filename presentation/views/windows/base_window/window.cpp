#include "window.h"

using namespace views::windows;

Window::Window(const std::string& title) {
	set_title(title);
	set_default_size(900, 600);
}
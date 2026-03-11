#include "window.h"

using namespace views::windows;

Window::Window(const std::string title) : Gtk::Window() {
	set_title(title);
}
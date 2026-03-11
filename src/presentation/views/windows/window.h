#pragma once
#include <gtkmm.h>
#include <string>

namespace views {
	namespace windows {
		class Window : public Gtk::Window {
		public:
			Window(const std::string title);
		};
	}
}
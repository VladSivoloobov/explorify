#include <gtkmm.h>
#include <string>
#include "SidebarParams.h"

namespace views {
	namespace widgets {
		class Sidebar : public Gtk::StackSidebar {
		public:
			Sidebar();
		private:
			void create_page(const SidebarParams params);
			Gtk::Stack stack;
		};
	}
}
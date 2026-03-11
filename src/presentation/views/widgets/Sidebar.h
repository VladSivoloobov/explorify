#include <gtkmm.h>
#include <string>
#include "SidebarPage.h"

namespace views {
	namespace widgets {
		class Sidebar : public Gtk::StackSidebar {
		public:
			Sidebar();
		private:
			void create_page(
				const std::string page_title,
				const std::string page_id,
				Gtk::Stack* stack
			);
		};
	}
}
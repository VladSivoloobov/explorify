#include <gtkmm.h>
#include <string>

namespace views {
	namespace widgets {
		class FileButton : public Gtk::Button {
		public:
			FileButton(std::string file_name);
		};
	}
}
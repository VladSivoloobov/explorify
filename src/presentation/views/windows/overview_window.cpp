#include "overview_window.h"
#include "../../../../constants.h"

using namespace views;

windows::OverviewWindow::OverviewWindow() : 
	Window(std::string(constants::PROJECT)) {
	auto* sidebar = create_sidebar();
	auto* stack = sidebar->get_stack();

	auto* box = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);

	box->append(*sidebar);
	box->append(*stack);

	set_child(*box);
};

widgets::Sidebar* windows::OverviewWindow::create_sidebar() {
	auto* sidebar = Gtk::make_managed<widgets::Sidebar>();

	return sidebar;
}
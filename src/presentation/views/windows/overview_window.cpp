#include "overview_window.h"
#include "../../../../constants.h"

using namespace views::windows;

OverviewWindow::OverviewWindow() : Window(std::string(constants::PROJECT)) {
	Gtk::Label label("Label!");

	this->set_child(label);
};
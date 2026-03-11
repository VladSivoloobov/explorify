#include "overview_window.h"
#include "../../../../constants.h"
#include "../../widgets/file_button/file_button.h"
#include <format>

using namespace views;

windows::OverviewWindow::OverviewWindow() 
	: windows::Window(std::string(constants::PROJECT)) {
	
	auto* scrolled_window = Gtk::make_managed<Gtk::ScrolledWindow>();
	auto* flow_box = Gtk::make_managed<Gtk::FlowBox>();

	for (int i = 0; i < 100; i++) {
		auto* button = Gtk::make_managed<widgets::FileButton>(std::format("File {}", i));

		flow_box->append(*button);
	}

	scrolled_window->set_child(*flow_box);
	set_child(*scrolled_window);
}
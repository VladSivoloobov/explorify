// explorify.cpp: определяет точку входа для приложения.
//
#include <iostream>
#include "src/presentation/views/windows/overview_window.h"
#include "constants.h"

int main(int argc, char* argv[])
{
	auto app = Gtk::Application::create("com.vladsivolobov.explorify");
	
	static std::shared_ptr<views::windows::OverviewWindow>window;

	return 
		app->signal_activate()
		.connect([app]() {
			if (!window) {
				window = std::make_shared<views::windows::OverviewWindow>();
				window->show();
				app->add_window(*window);
			}
		}), app->run();
}
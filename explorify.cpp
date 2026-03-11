// explorify.cpp: определяет точку входа для приложения.
//
#include <iostream>
#include "src/presentation/views/windows/window.h"

int main(int argc, char* argv[])
{
	auto app = Gtk::Application::create("com.vladsivolobov.explorify");
	
	static std::shared_ptr<views::windows::Window>window;

	return 
		app->signal_activate()
		.connect([app]() {
			if (!window) {
				window = std::make_shared<views::windows::Window>("Test");
				window->show();
				app->add_window(*window);
			}
		}), app->run();
}
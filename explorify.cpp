// explorify.cpp: определяет точку входа для приложения.
//
#include <iostream>
#include "presentation/views/windows/overview_window/overview_window.h"
#include "constants.h"
#include <filesystem>

void load_css();

int main(int argc, char* argv[])
{
	auto app = Gtk::Application::create("com.vladsivolobov.explorify");

	static std::shared_ptr<views::windows::OverviewWindow> window;

	load_css();

	return
		app->signal_activate()
		.connect([app]() {
			if (!window) {
				auto display = Gdk::Display::get_default();
				auto icon_theme = Gtk::IconTheme::get_for_display(display);

				std::string icon_path = std::filesystem::current_path().string() + "/theme/adwaita-icon-theme";
				icon_theme->add_search_path(icon_path);

				window = std::make_shared<views::windows::OverviewWindow>();
				window->show();
				app->add_window(*window);
			}
		}), app->run();
}

static void load_css() {
	auto css_provider = Gtk::CssProvider::create();

	std::string css_path = std::filesystem::current_path().string() + "/styles/styles.css";

	css_provider->load_from_path(css_path);

	Gtk::StyleContext::add_provider_for_display(
		Gdk::Display::get_default(),
		css_provider,
		GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
	);
}
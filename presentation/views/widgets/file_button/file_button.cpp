#include "file_button.h"

using namespace views::widgets;

FileButton::FileButton(std::string file_name) {

	auto box = Gtk::make_managed<Gtk::Box>(
		Gtk::Orientation::VERTICAL,
		8
	);
	auto icon = Gtk::make_managed<Gtk::Image>();

	icon->set_from_icon_name("folder");

	auto label = Gtk::make_managed<Gtk::Label>(file_name);

	box->append(*icon);
	box->append(*label);

	add_css_class("folder-button");
	box->add_css_class("folder-button__box");
	icon->add_css_class("folder-button__icon");
	label->add_css_class("folder-button__label");

	set_child(*box);
}
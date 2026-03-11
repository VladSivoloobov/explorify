#include "Sidebar.h"

using namespace views::widgets;

Sidebar::Sidebar() : Gtk::StackSidebar(){
	Gtk::Stack stack;

	create_page("Избранное", "favor", *stack);
};

void Sidebar::create_page(
	const std::string page_title,
	const std::string page_id,
	Gtk::Stack* stack
) {
	Gtk::Label label(page_title);

	stack->add(label, page_id, page_title);
}
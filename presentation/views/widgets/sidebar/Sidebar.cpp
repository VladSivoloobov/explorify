#include "Sidebar.h"
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace views::widgets;

Sidebar::Sidebar() : Gtk::StackSidebar(){
	std::vector<SidebarParams> pages {
		{
			"Page 1", "page_1", "Page 1",
		},
		{
			"Page 2", "page_2", "Page 2",
		},
		{
			"Page 3", "page_3", "Page 3"
		}
	};

	for (auto& page : pages) {
		create_page(page);

		std::cout << page.page_title << std::endl;
	}

	set_stack(stack);
};

void Sidebar::create_page(const SidebarParams params) {
	auto* label = Gtk::make_managed<Gtk::Label>(params.page_name);

	stack.add(*label, params.page_id, params.page_title);
}
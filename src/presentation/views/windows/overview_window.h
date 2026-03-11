#pragma once
#include "window.h"
#include "../widgets/Sidebar.h"

namespace views {
	namespace windows{
		class OverviewWindow : public Window {
		public:
			OverviewWindow();

		private:
			views::widgets::Sidebar* create_sidebar();
		};
	}
}
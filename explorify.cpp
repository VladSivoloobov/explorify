// explorify.cpp: определяет точку входа для приложения.
//
#include <iostream>
#include "src/presentation/views/windows/window.h"

int main()
{
	views::windows::Window window("Test window");

	window.show();
}

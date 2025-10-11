#include "App.h"
#include "Window.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	// what is it that our OnInit method should do?
	// open the window
	window = new Window();
	window->Show();
	return true;
}

// change
// another change
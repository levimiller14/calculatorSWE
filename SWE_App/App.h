#pragma once
#include "wx/wx.h"

// forward declare class
// Window.h doesn't have a dependency (good thing)
class Window;

// What does this need to get going? 
// At some point, its going to have to display a window.
// We create a new class called Window

// we need to inherit from a wxwidget object
class App : public wxApp
{
	// we need to have a pointer to our window
	Window* window = nullptr;
public:
	// when it inherits from that, we are going to need to implement
	virtual bool OnInit();
};
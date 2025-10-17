#include "ButtonFactory.h"
#include "Window.h"

const wxSize ButtonFactory::BUTTON_SIZE(50, 50);

wxButton* ButtonFactory::CreateButton(wxWindow* parent, int id, const wxString& label, const wxPoint& pos, const wxSize& size)
{
	return new wxButton(parent, id, label, pos, size);
}

wxButton* ButtonFactory::CreateStandardButton(wxWindow* parent, int id, const wxString& label, int x, int y)
{
	return new wxButton(parent, id, label, wxPoint(x, y), BUTTON_SIZE);
}

// refactored, created all and TODO: update in Window.cpp
wxButton* ButtonFactory::CreateNumber0Button(wxWindow* parent)
{
	return CreateStandardButton(parent, Window::ID_NUMBER_0, "0", 10, 400);
}

wxButton* ButtonFactory::CreateNumber1Button(wxWindow* parent)
{
	return CreateStandardButton(parent, Window::ID_NUMBER_1, "1", 10, 350);
}

wxButton* ButtonFactory::CreateNumber2Button(wxWindow* parent)
{
	return CreateStandardButton(parent, Window::ID_NUMBER_2, "2", 60, 350);
}

wxButton* ButtonFactory::CreateNumber3Button(wxWindow* parent)
{
	return CreateStandardButton(parent, Window::ID_NUMBER_3, "3", 110, 350);
}

wxButton* ButtonFactory::CreateNumber4Button(wxWindow* parent)
{
	return CreateStandardButton(parent, Window::ID_NUMBER_4, "4", 10, 300);
}

wxButton* ButtonFactory::CreateNumber5Button(wxWindow* parent)
{
	return CreateStandardButton(parent, Window::ID_NUMBER_5, "5", 60, 300);
}

wxButton* ButtonFactory::CreateNumber6Button(wxWindow* parent)
{
	return CreateStandardButton(parent, Window::ID_NUMBER_6, "6", 110, 300);
}

wxButton* ButtonFactory::CreateNumber7Button(wxWindow* parent)
{
	return CreateStandardButton(parent, Window::ID_NUMBER_7, "7", 10, 250);
}

wxButton* ButtonFactory::CreateNumber8Button(wxWindow* parent)
{
	return CreateStandardButton(parent, Window::ID_NUMBER_8, "8", 60, 250);
}

wxButton* ButtonFactory::CreateNumber9Button(wxWindow* parent)
{
	return CreateStandardButton(parent, Window::ID_NUMBER_9, "9", 110, 250);
}

wxButton* ButtonFactory::CreateAddButton(wxWindow* parent)
{
	return CreateStandardButton(parent, Window::ID_ADD, "+", 160, 350);
}

wxButton* ButtonFactory::CreateSubButton(wxWindow* parent)
{
	return CreateStandardButton(parent, Window::ID_SUB, "-", 210, 350);
}

wxButton* ButtonFactory::CreateMultButton(wxWindow* parent)
{
	return CreateStandardButton(parent, Window::ID_MULT, "*", 160, 300);
}

wxButton* ButtonFactory::CreateDivButton(wxWindow* parent)
{
	return CreateStandardButton(parent, Window::ID_DIV, "/", 210, 300);
}

wxButton* ButtonFactory::CreateModButton(wxWindow* parent)
{
	return CreateStandardButton(parent, Window::ID_MOD, "mod", 210, 400);
}

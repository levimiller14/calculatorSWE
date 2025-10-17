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

// forgot these in pt 1. finishing here
wxButton* ButtonFactory::CreateSinButton(wxWindow* parent)
{
	return CreateStandardButton(parent, Window::ID_SIN, "sin(x)", 60, 200);
}

wxButton* ButtonFactory::CreateCosButton(wxWindow* parent)
{
	return CreateStandardButton(parent, Window::ID_COS, "cos(x)", 110, 200);
}

wxButton* ButtonFactory::CreateTanButton(wxWindow* parent)
{
	return CreateStandardButton(parent, Window::ID_TAN, "tan(x)", 160, 200);
}

wxButton* ButtonFactory::CreateEqualsButton(wxWindow* parent)
{
	return CreateStandardButton(parent, Window::ID_EQUALS, "=", 160, 400);
}

wxButton* ButtonFactory::CreateACButton(wxWindow* parent)
{
	return CreateStandardButton(parent, Window::ID_AC, "AC", 210, 250);
}

wxButton* ButtonFactory::CreateNegativeButton(wxWindow* parent)
{
	return CreateStandardButton(parent, Window::ID_C, "C", 160, 250);
}

wxButton* ButtonFactory::CreateCButton(wxWindow* parent)
{
	return CreateStandardButton(parent, Window::ID_DECIMAL, ".", 60, 400);
}

wxButton* ButtonFactory::CreateDecimalButton(wxWindow* parent)
{
	return CreateStandardButton(parent, Window::ID_NEGATIVE, "-(x)", 110, 400);
}

// returns text to be appended upon  button Click
wxString ButtonFactory::GetButtonText(int buttonId)
{
	switch (buttonId)
	{
		// 0-9
		case Window::ID_NUMBER_0: return "0";
		case Window::ID_NUMBER_1: return "1";
		case Window::ID_NUMBER_2: return "2";
		case Window::ID_NUMBER_3: return "3";
		case Window::ID_NUMBER_4: return "4";
		case Window::ID_NUMBER_5: return "5";
		case Window::ID_NUMBER_6: return "6";
		case Window::ID_NUMBER_7: return "7";
		case Window::ID_NUMBER_8: return "8";
		case Window::ID_NUMBER_9: return "9";

		// binary
		case Window::ID_ADD: return "+";
		case Window::ID_SUB: return "-";
		case Window::ID_MULT: return "*";
		case Window::ID_DIV: return "/";
		case Window::ID_MOD: return "mod";

		// unary
		case Window::ID_SIN: return "sin";
		case Window::ID_COS: return "cos";
		case Window::ID_TAN: return "tan";

		// symbols
		case Window::ID_DECIMAL: return ".";
		case Window::ID_NEGATIVE: return "-";
		
		// AC/C/=
		default: return "";
	}
	return wxString();
}
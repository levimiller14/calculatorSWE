#pragma once
#include "wx/wx.h"

// Part One: Button Factory
// Create a new branch from existing main branch
// On the new branch, create a new class called, ButtonFactory (methods may be static)
// Inside ButtonFactory, create functions that facilitate creating each button,
// should have one method for generically creating buttons based off of parameters and multiple methods for each
// Change logic in main calculator app to use ButtonFactory

class ButtonFactory
{
public:

	// may be static
	static wxButton* CreateButton(wxWindow* parent, int id, const wxString& label,
		const wxPoint& pos, const wxSize& size);

	// create all button methods (ButtonFactory)
	static wxButton* CreateNumber0Button(wxWindow* parent);
	static wxButton* CreateNumber1Button(wxWindow* parent);
	static wxButton* CreateNumber2Button(wxWindow* parent);
	static wxButton* CreateNumber3Button(wxWindow* parent);
	static wxButton* CreateNumber4Button(wxWindow* parent);
	static wxButton* CreateNumber5Button(wxWindow* parent);
	static wxButton* CreateNumber6Button(wxWindow* parent);
	static wxButton* CreateNumber7Button(wxWindow* parent);
	static wxButton* CreateNumber8Button(wxWindow* parent);
	static wxButton* CreateNumber9Button(wxWindow* parent);

	static wxButton* CreateAddButton(wxWindow* parent);
	static wxButton* CreateSubButton(wxWindow* parent);
	static wxButton* CreateMultButton(wxWindow* parent);
	static wxButton* CreateDivButton(wxWindow* parent);
	static wxButton* CreateModButton(wxWindow* parent);

	//static wxButton* CreateNumber0Button(wxWindow* parent);
	//static wxButton* CreateNumber0Button(wxWindow* parent);
	//static wxButton* CreateNumber0Button(wxWindow* parent);
	//static wxButton* CreateNumber0Button(wxWindow* parent);
	//static wxButton* CreateNumber0Button(wxWindow* parent);
	//static wxButton* CreateNumber0Button(wxWindow* parent);
	//static wxButton* CreateNumber0Button(wxWindow* parent);
	//static wxButton* CreateNumber0Button(wxWindow* parent);
	//static wxButton* CreateNumber0Button(wxWindow* parent);
	//static wxButton* CreateNumber0Button(wxWindow* parent);
	//static wxButton* CreateNumber0Button(wxWindow* parent);

private:
	static const wxSize BUTTON_SIZE;
	static wxButton* CreateStandardButton(wxWindow* parent, int id, const wxString& label, int x, int y);

};


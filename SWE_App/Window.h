#pragma once
#include "wx/wx.h"

class Window : public wxFrame
{
private:
	// Event handler function
	void OnButtonClick(wxCommandEvent& event);

	// Equals Button/Calculations
	bool EvaluateExpression(wxString expression, double& result);


	// lets add buttons (23 total(?), probably need more, PEMDAS w exponent signs and parentheses etc)
	// name as the corresponding buttons for ease of access/teamwork etc
	// text box 
	// a.) A text control
	wxTextCtrl* textBox = nullptr;
	// b.) Numbers 0-9
	wxButton* number0 = nullptr;
	wxButton* number1 = nullptr;
	wxButton* number2 = nullptr;
	wxButton* number3 = nullptr;
	wxButton* number4 = nullptr;
	wxButton* number5 = nullptr;
	wxButton* number6 = nullptr;
	wxButton* number7 = nullptr;
	wxButton* number8 = nullptr;
	wxButton* number9 = nullptr;
	// c.) Binary Operators: +, -, *, /, % (as modulo)
	wxButton* add = nullptr;
	wxButton* sub = nullptr;
	wxButton* mult = nullptr;
	wxButton* div = nullptr;
	wxButton* mod = nullptr;
	// d.) Unary Operators: sin, cos, tan (rads and/or deg)
	wxButton* sin = nullptr;
	wxButton* cos = nullptr;
	wxButton* tan = nullptr;
	// e.) Equals: = 
	wxButton* equals = nullptr;
	// f.) Clear 
	wxButton* AC = nullptr;
	// g.) Backspace/delete
	wxButton* C = nullptr;
	// h.) Decimal (adds decimal point to text control)
	wxButton* decimal = nullptr;
	// i.) Negative (adds a negative symbol to the text control)
	wxButton* negative = nullptr;

	// part 2: Event Handling Instructions
	// "Create a new branch from your exisitng main branch. Give branch a name that will recognizeable as event works"
	// can't create branches, as communicated and shared in discord and 2.4 Lab - Calculator Design UI and Event Handling
	// implement event table that handles click events for each button, DO NOT USE BIND
	wxDECLARE_EVENT_TABLE();

public:
	// default constructor for our window
	Window();

	// moved to public: IDs more accessible to ButtonFactory
	// enumerator for Button IDs?
	enum
	{
		ID_NUMBER_0,
		ID_NUMBER_1,
		ID_NUMBER_2,
		ID_NUMBER_3,
		ID_NUMBER_4,
		ID_NUMBER_5,
		ID_NUMBER_6,
		ID_NUMBER_7,
		ID_NUMBER_8,
		ID_NUMBER_9,
		ID_ADD,
		ID_SUB,
		ID_MULT,
		ID_DIV,
		ID_MOD,
		ID_SIN,
		ID_COS,
		ID_TAN,
		ID_EQUALS,
		ID_AC,
		ID_C,
		ID_DECIMAL,
		ID_NEGATIVE
	};
};


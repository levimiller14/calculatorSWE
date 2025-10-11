#include "Window.h"

// part 2
// event table in implementation file (Window.cpp), tells wxWidgets how to map events to member functions
wxBEGIN_EVENT_TABLE(Window, wxFrame)
	// example from docs.wxwidgets.org/3.1/overview_events.html
	//EVT_MENU(wxID_EXIT, MyFrame::OnExit)
	//EVT_MENU(DO TEST, MyFrame::DoTest)
	//EVT_SIZE(MyFrame::OnSize)
	//EVT_BUTTON(BUTTON1, MyFrame::OnButton1)
	// MyFrame would become Window?
	// Button Functionality
	// 1.) When the buttons are pressed, they are added to text control
	// a.) Numbers 0-9
	EVT_BUTTON(ID_NUMBER_0, OnButtonClick)
	EVT_BUTTON(ID_NUMBER_1, OnButtonClick)
	EVT_BUTTON(ID_NUMBER_2, OnButtonClick)
	EVT_BUTTON(ID_NUMBER_3, OnButtonClick)
	EVT_BUTTON(ID_NUMBER_4, OnButtonClick)
	EVT_BUTTON(ID_NUMBER_5, OnButtonClick)
	EVT_BUTTON(ID_NUMBER_6, OnButtonClick)
	EVT_BUTTON(ID_NUMBER_7, OnButtonClick)
	EVT_BUTTON(ID_NUMBER_8, OnButtonClick)
	EVT_BUTTON(ID_NUMBER_9, OnButtonClick)
	// b.) Binary Operators
	EVT_BUTTON(ID_ADD, OnButtonClick)
	EVT_BUTTON(ID_SUB, OnButtonClick)
	EVT_BUTTON(ID_MULT,OnButtonClick)
	EVT_BUTTON(ID_DIV, OnButtonClick)
	EVT_BUTTON(ID_MOD, OnButtonClick)
	// c.) Decimal
	EVT_BUTTON(ID_DECIMAL, OnButtonClick)
	// d.) Negative
	EVT_BUTTON(ID_NEGATIVE, OnButtonClick)
	// e.) Unary Operators
	EVT_BUTTON(ID_SIN, OnButtonClick)
	EVT_BUTTON(ID_COS, OnButtonClick)
	EVT_BUTTON(ID_TAN, OnButtonClick)
	// f.) Clear Button 
	EVT_BUTTON(ID_AC, OnButtonClick)
	// g.) Backspace/Delete
	EVT_BUTTON(ID_C, OnButtonClick)
	// e.) Equals
	EVT_BUTTON(ID_EQUALS, OnButtonClick)
wxEND_EVENT_TABLE();

// OnButtonClick implementation
void Window::OnButtonClick(wxCommandEvent& event)
{
	// when a button of certain ID clicked
	// do something

	// Button Functionality
	int id = event.GetId();
	// 1.) When the following buttons are pressed, button label should be added to textbox
	switch (id)
	{
		// a.) Numbers 0-9
		case ID_NUMBER_0:
			// adds to text box
			textBox->AppendText("0");
			break;
		case ID_NUMBER_1:
			textBox->AppendText("1");
			break;
		case ID_NUMBER_2:
			textBox->AppendText("2");
			break;
		case ID_NUMBER_3:
			textBox->AppendText("3");
			break;
		case ID_NUMBER_4:
			textBox->AppendText("4");
			break;
		case ID_NUMBER_5:
			textBox->AppendText("5");
			break;
		case ID_NUMBER_6:
			textBox->AppendText("6");
			break;
		case ID_NUMBER_7:
			textBox->AppendText("7");
			break;
		case ID_NUMBER_8:
			textBox->AppendText("8");
			break;
		case ID_NUMBER_9:
			textBox->AppendText("9");
			break;

		// b.) Binary Operators
		case ID_ADD:
			textBox->AppendText("+");
			break;
		case ID_SUB:
			textBox->AppendText("-");
			break;
		case ID_MULT:
			textBox->AppendText("*");
			break;
		case ID_DIV:
			textBox->AppendText("/");
			break;
		case ID_MOD:
			textBox->AppendText("");
			break;

		// c.) Decimal
		case ID_DECIMAL:
			textBox->AppendText(".");
			break;

		// d.) Negative
		case ID_NEGATIVE:
			textBox->AppendText("-");
			break;

		// e.) Unary Operators
		case ID_SIN:
			textBox->AppendText("sin");
			break;
		case ID_COS:
			textBox->AppendText("cos");
			break;
		case ID_TAN:
			textBox->AppendText("tan");
			break;

		// Clear (fully clear text box)
		case ID_AC:
			textBox->Clear();
			break;

		// Backspace (one character at a time)
		case ID_C:
		{

			// if textBox not empty
			wxString text = textBox->GetValue();
			// special cases for sin/cos/tan because they are stubborn assholes
			// if text finisher is "sin/cos/tan"
			if (text.EndsWith("sin"))
			{
				// set current textBox Value to text - 3 (letters sin/cos/tan)
				textBox->SetValue(text.substr(0, text.Length() - 3));
			}
			else if (text.EndsWith("cos"))
			{
				textBox->SetValue(text.substr(0, text.Length() - 3));
			}
			else if (text.EndsWith("tan"))
			{
				textBox->SetValue(text.substr(0, text.Length() - 3));
			}
			else if (!text.IsEmpty())
			{
				text.RemoveLast();
				textBox->SetValue(text);
			}
			break;
		}
			
		// Equals (calculate whatever string, clear it, display result in textbox)
		case ID_EQUALS:
			// Equals Button/Calculations
			//
			//textBox->AppendText("=");
			break;
	}
	
}

// Equals Button/Calculations Implementation
double Window::EvaluateExpression(wxString expression)
{
	return 0.0;
}

Window::Window() : wxFrame(nullptr, wxID_ANY, "CALCULATOR", wxPoint(200, 200), wxSize(500, 500))
{
	// Initialize buttons in constructor:
	// change text entries 
	// size of buttons should be same, but start at different location
	// a.) A text control
	textBox = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 120), wxSize(250, 30));
	// b.) Numbers 0-9
	number0 = new wxButton(this, ID_NUMBER_0, "0", wxPoint(10, 400), wxSize(50, 50));
	number1 = new wxButton(this, ID_NUMBER_1, "1", wxPoint(10, 350), wxSize(50, 50));
	number2 = new wxButton(this, ID_NUMBER_2, "2", wxPoint(60, 350), wxSize(50, 50));
	number3 = new wxButton(this, ID_NUMBER_3, "3", wxPoint(110, 350), wxSize(50, 50));
	number4 = new wxButton(this, ID_NUMBER_4, "4", wxPoint(10, 300), wxSize(50, 50));
	number5 = new wxButton(this, ID_NUMBER_5, "5", wxPoint(60, 300), wxSize(50, 50));
	number6 = new wxButton(this, ID_NUMBER_6, "6", wxPoint(110, 300), wxSize(50, 50));
	number7 = new wxButton(this, ID_NUMBER_7, "7", wxPoint(10, 250), wxSize(50, 50));
	number8 = new wxButton(this, ID_NUMBER_8, "8", wxPoint(60, 250), wxSize(50, 50));
	number9 = new wxButton(this, ID_NUMBER_9, "9", wxPoint(110, 250), wxSize(50, 50));
	// c.) Binary Operators: +, -, *, /, % (as modulo)
	add = new wxButton(this, ID_ADD, "+", wxPoint(160, 350), wxSize(50, 50));
	sub = new wxButton(this, ID_SUB, "-", wxPoint(210, 350), wxSize(50, 50));
	mult = new wxButton(this, ID_MULT, "*", wxPoint(160, 300), wxSize(50, 50));
	div = new wxButton(this, ID_DIV, "/", wxPoint(210, 300), wxSize(50, 50));
	mod = new wxButton(this, ID_MOD, "mod", wxPoint(210, 400), wxSize(50, 50));
	// d.) Unary Operators: sin, cos, tan (rads and/or deg)
	sin = new wxButton(this, ID_SIN, "sin(x)", wxPoint(60, 200), wxSize(50, 50));
	cos = new wxButton(this, ID_COS, "cos(x)", wxPoint(110, 200), wxSize(50, 50));
	tan = new wxButton(this, ID_TAN, "tan(x)", wxPoint(160, 200), wxSize(50, 50));
	// e.) Equals: = 
	equals = new wxButton(this, ID_EQUALS, "=", wxPoint(160, 400), wxSize(50, 50));
	// f.) Clear 
	AC = new wxButton(this, ID_AC, "AC", wxPoint(210, 250), wxSize(50, 50));
	// g.) Backspace/delete
	C = new wxButton(this, ID_C, "C", wxPoint(160, 250), wxSize(50, 50));
	// h.) Decimal (adds decimal point to text control)
	decimal = new wxButton(this, ID_DECIMAL, ".", wxPoint(60, 400), wxSize(50, 50));
	// i.) Negative (adds a negative symbol to the text control)
	negative = new wxButton(this, ID_NEGATIVE, "-(x)", wxPoint(110, 400), wxSize(50, 50));

}
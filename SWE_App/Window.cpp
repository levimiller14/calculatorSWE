#include "Window.h" 
#include "wx/tokenzr.h"
#include <cmath>
#include "ButtonFactory.h"

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
			textBox->AppendText("%");
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
			// Implement simple calculations/evaluations
			wxString expression = textBox->GetValue();

			// empty?
			if (expression.IsEmpty())
			{
				break; // nothing
			}

			double result = 0;
			bool success = EvaluateExpression(expression, result);

			if (success)
			{
				double rounded = round(result * 100.0) / 100.0;
				textBox->SetValue(std::to_string(rounded));
			}
			else
			{
				textBox->SetValue("Error");
			}
			break;
	}
			//textBox->AppendText("=");
}

// Equals Button/Calculations Implementation
bool Window::EvaluateExpression(wxString expression, double& result)
{

	const double pidiv180 = 3.14159265359 / 180;

	try
	{
		for (int i = 1; i < expression.Length() - 2; i++)
		{
			//check for digits before trig 
			if (wxIsdigit(expression[i - 1]))
			{
				if (expression.Mid(i, 3) == "sin" || expression.Mid(i, 3) == "cos" || expression.Mid(i, 3) == "tan")
				{
					// handle mult between value and trig
					expression = expression.Mid(0, i) + "*" + expression.Mid(i);
					break;
				}
			}
		}
		
		// FIND OPERATOR POSITION
		wxString op = "";
		int opPos = -1;

		for (int i = 0; i < expression.Length(); i++)
		{
			wxChar c = expression[i];
			if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
			{
				op = c;
				opPos = i;
				break;
			}
		}

		// If found - Binary
		if (opPos != -1)
		{
			wxString leftStr = expression.Mid(0, opPos);
			wxString rightStr = expression.Mid(opPos + 1);

			if (leftStr.IsEmpty() || rightStr.IsEmpty())
				return false;

			double num1 = 0;
			double num2 = 0;

			// Evaluate LEFT SIDE
			if (leftStr.StartsWith("sin"))
			{
				wxString numStr = leftStr.Mid(3);
				double angle;
				if (numStr.IsEmpty() || !numStr.ToDouble(&angle))
					return false;
				num1 = std::sin(angle * pidiv180);
			}
			else if (leftStr.StartsWith("cos"))
			{
				wxString numStr = leftStr.Mid(3);
				double angle;
				if (numStr.IsEmpty() || !numStr.ToDouble(&angle))
					return false;
				num1 = std::cos(angle * pidiv180);
			}
			else if (leftStr.StartsWith("tan"))
			{
				wxString numStr = leftStr.Mid(3);
				double angle;
				if (numStr.IsEmpty() || !numStr.ToDouble(&angle))
					return false;
				num1 = std::tan(angle * pidiv180);
			}
			else
			{
				num1 = std::stod(leftStr.ToStdString());
			}
			// RIGHT SIDE
			if (rightStr.StartsWith("sin"))
			{
				wxString numStr = rightStr.Mid(3);
				double angle;
				if (numStr.IsEmpty() || !numStr.ToDouble(&angle))
					return false;
				num2 = std::sin(angle * pidiv180);
			}
			else if (rightStr.StartsWith("cos"))
			{
				wxString numStr = rightStr.Mid(3);
				double angle;
				if (numStr.IsEmpty() || !numStr.ToDouble(&angle))
					return false;
				num2 = std::cos(angle * pidiv180);
			}
			else if (rightStr.StartsWith("tan"))
			{
				wxString numStr = rightStr.Mid(3);
				double angle;
				if (numStr.IsEmpty() || !numStr.ToDouble(&angle))
					return false;
				num2 = std::tan(angle * pidiv180);
			}
			else
			{
				num2 = std::stod(rightStr.ToStdString());
			}

			// perform OPERATION
			if (op == "+")
				result = num1 + num2;
			else if (op == "-")
				result = num1 - num2;
			else if (op == "*")
				result = num1 * num2;
			else if (op == "/")
			{
				if (num2 == 0)
					return false;
				result = num1 / num2;
			}
			else if (op == "%")
			{
				if (num2 == 0)
					return false;
				result = fmod(num1, num2);
			}
			else
				return false;

			return true;
		}
		else
		{
			// NO OPERATOR just trig function/number
			if (expression.StartsWith("sin"))
			{
				wxString numStr = expression.Mid(3);
				double angle;
				if (numStr.IsEmpty() || !numStr.ToDouble(&angle))
					return false;
				result = std::sin(angle * pidiv180);
				return true;
			}
			else if (expression.StartsWith("cos"))
			{
				wxString numStr = expression.Mid(3);
				double angle;
				if (numStr.IsEmpty() || !numStr.ToDouble(&angle))
					return false;
				result = std::cos(angle * pidiv180);
				return true;
			}
			else if (expression.StartsWith("tan"))
			{
				wxString numStr = expression.Mid(3);
				double angle;
				if (numStr.IsEmpty() || !numStr.ToDouble(&angle))
					return false;
				result = std::tan(angle * pidiv180);
				return true;
			}
			else
			{
				result = std::stod(expression.ToStdString());
				return true;
			}
		}
	}
	catch (const std::invalid_argument&)
	{
		return false;
	}
	catch (const std::out_of_range&)
	{
		return false;
	}
	// "CATCH ALL"
	catch (...)
	{
		return false;
	}

	// can't handle 8sin180 ... "implied multiplication"
	//for (int i = 1; i < expression.Length() - 2; i++)
	//{
	//	//check for digits before trig 
	//	if (wxIsdigit(expression[i - 1]))
	//	{
	//		if (expression.Mid(i, 3) == "sin" || expression.Mid(i, 3) == "cos" || expression.Mid(i, 3) == "tan")
	//		{
	//			// handle mult between value and trig
	//			expression = expression.Mid(0, i) + "*" + expression.Mid(i);
	//			break;
	//		}
	//	}
	//}
	//// that didnt work smh
	
	// what the fuck am i doingggggggggg
	//try
	//{
	//	// BINARY
	//	// find operator position?
	//	wxString op = "";
	//	int opPos = -1;
	//
	//	for (int i = 0; i < expression.Length(); i++)
	//	{
	//		wxChar c = expression[i];
	//		if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
	//		{
	//			op = c;
	//			opPos = i;
	//			break;
	//		}
	//	}
	//	if (opPos == -1)
	//	{
	//		// split expression at operator
	//		wxString leftStr = expression.Mid(0, opPos);
	//		wxString rightStr = expression.Mid(opPos + 1);
	//
	//		if (leftStr.IsEmpty() || rightStr.IsEmpty())
	//			return false;
	//
	//		double num1, num2;
	//
	//		//// UNARY
	//		// sin
	//		if (expression.StartsWith("sin"))
	//		{
	//			wxString numStr = expression.Mid(3);
	//
	//			if (numStr.IsEmpty() || !numStr.ToDouble(&num1))
	//			{
	//				return false;
	//				num1 = std::sin(num1 * pidiv180);
	//			}
	//		}
	//		// cos
	//		else if (expression.StartsWith("cos"))
	//		{
	//			wxString numStr = expression.Mid(3);
	//			if (numStr.IsEmpty() || !numStr.ToDouble(&num1))
	//			{
	//				return false;
	//				num1 = std::cos(num1 * pidiv180);
	//			}
	//		}
	//		// tan
	//		else if (expression.StartsWith("tan"))
	//		{
	//			wxString numStr = expression.Mid(3);
	//			if (numStr.IsEmpty() || !numStr.ToDouble(&num1))
	//			{
	//				return false;
	//				num1 = std::tan(num1 * pidiv180);
	//			}
	//			else
	//			{
	//				num1 = std::stod(leftStr.ToStdString());
	//			}
	//			if (rightStr.StartsWith("sin"))
	//			{
	//				wxString numStr = rightStr.Mid(3);
	//				if (numStr.IsEmpty() || !numStr.ToDouble(&num2))
	//				{
	//					return false;
	//					num2 = std::sin(num2 * pidiv180);
	//				}
	//				else if (rightStr.StartsWith("cos"))
	//				{
	//					wxString numStr = rightStr.Mid(3);
	//					if (numStr.IsEmpty() || !numStr.ToDouble(&num2))
	//					{
	//						return false;
	//						num2 = std::cos(num2 * pidiv180);
	//					}
	//				}
	//				else if (rightStr.StartsWith("tan"))
	//				{
	//					wxString numStr = rightStr.Mid(3);
	//					if (numStr.IsEmpty() || !numStr.ToDouble(&num2))
	//					{
	//						return false;
	//						num2 = std::tan(num2 * pidiv180);
	//					}
	//				}
	//				else
	//				{
	//					// right side regular number
	//					num2 = std::stod(rightStr.ToStdString());
	//				}
	//				//addition
	//				if (op == "+")
	//				{
	//					result = num1 + num2;
	//					return true;
	//				}
	//				// subtraction
	//				else if (op == "-")
	//				{
	//					result = num1 - num2;
	//					return true;
	//				}
	//				// multiplication
	//				else if (op == "*")
	//				{
	//					result = num1 * num2;
	//					return true;
	//				}
	//				// division
	//				else if (op == "/")
	//				{
	//					// handle div by 0
	//					if (num2 == 0)
	//						return false;
	//					//
	//					result = num1 / num2;
	//					return true;
	//				}
	//				// mod
	//				else if (op == "%")
	//				{
	//					// handle by 0
	//					if (num2 == 0)
	//						return false;
	//					result = fmod(num1, num2);
	//					return true;
	//				}
	//			}
	//			else
	//			{
	//				// no operator found , just trig function?
	//				if (expression.StartsWith("sin"))
	//				{
	//					wxString numStr = expression.Mid(3);
	//					if (numStr.IsEmpty())
	//						return false;
	//
	//					double angle;
	//					if (!numStr.ToDouble(&angle))
	//						return false;
	//
	//					result = std::sin(angle * pidiv180);
	//					return true;
	//				}
	//				else if (expression.StartsWith("cos"))
	//				{
	//					wxString numStr = expression.Mid(3);
	//					if (numStr.IsEmpty())
	//						return false;
	//
	//					double angle;
	//					if (!numStr.ToDouble(&angle))
	//						return false;
	//
	//					result = std::cos(angle * pidiv180);
	//					return true;
	//				}
	//				else if (expression.StartsWith("tan"))
	//				{
	//					wxString numStr = expression.Mid(3);
	//					if (numStr.IsEmpty())
	//						return false;
	//
	//					double angle;
	//					if (!numStr.ToDouble(&angle))
	//						return false;
	//
	//					result = std::tan(angle * pidiv180);
	//					return true;
	//				}
	//			}
	//		}
	//		catch (const std::invalid_argument&)
	//		{
	//			return false;
	//		}
	//		catch (const std::out_of_range&)
	//		{
	//			return false;
	//		}
	//		return false;
	//}
	//
	//// tryCatchOverhaul?
	//// handle invalid conversions
	//
	//	double num1 = std::stod(leftStr.ToStdString());
	//	double num2 = std::stod(rightStr.ToStdString());
	//
	//	// addition
	//	if (op == "+")
	//	{
	//		result = num1 + num2;
	//		return true;
	//	}
	//	// subtraction
	//	else if (op == "-")
	//	{
	//		result = num1 - num2;
	//		return true;
	//	}
	//	// multiplication
	//	else if (op == "*")
	//	{
	//		result = num1 * num2;
	//		return true;
	//	}
	//	// division
	//	else if (op == "/")
	//	{
	//		// handle div by 0
	//		if (num2 == 0)
	//			return false;
	//		//
	//		result = num1 / num2;
	//		return true;
	//	}
	//	// mod
	//	else if (op == "%")
	//	{
	//		// handle by 0
	//		if (num2 == 0)
	//			return false;
	//		result = fmod(num1, num2);
	//		return true;
	//	}
	//}
	//// invalid formatting
	//catch (const std::invalid_argument&)
	//{
	//	return false;
	//}
	//// number too large
	//catch (const std::out_of_range&)
	//{
	//	return false; 
	//}
	//// unkown operator
	//return false;

}

Window::Window() : wxFrame(nullptr, wxID_ANY, "CALCULATOR", wxPoint(200, 200), wxSize(500, 500))
{
	// Initialize buttons in constructor:
	// change text entries 
	// size of buttons should be same, but start at different location
	// a.) A text control
	textBox = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 120), wxSize(250, 30));
	// b.) Numbers 0-9
	//number0 = new wxButton(this, ID_NUMBER_0, "0", wxPoint(10, 400), wxSize(50, 50));
	// testing ButtonFactory  implementation
	// "built" buttonfactory, set up coords pos output etc there, simplified here
	number0 = ButtonFactory::CreateNumber0Button(this);
	number1 = ButtonFactory::CreateNumber1Button(this);
	number2 = ButtonFactory::CreateNumber2Button(this);
	number3 = ButtonFactory::CreateNumber3Button(this);
	number4 = ButtonFactory::CreateNumber4Button(this);
	number5 = ButtonFactory::CreateNumber5Button(this);
	number6 = ButtonFactory::CreateNumber6Button(this);
	number7 = ButtonFactory::CreateNumber7Button(this);
	number8 = ButtonFactory::CreateNumber8Button(this);
	number9 = ButtonFactory::CreateNumber9Button(this);

	add = ButtonFactory::CreateAddButton(this);
	sub = ButtonFactory::CreateSubButton(this);
	mult = ButtonFactory::CreateMultButton(this);
	div = ButtonFactory::CreateDivButton(this);
	mod = ButtonFactory::CreateModButton(this);

	sin = ButtonFactory::CreateSinButton(this);
	cos = ButtonFactory::CreateCosButton(this);
	tan = ButtonFactory::CreateTanButton(this);

	equals = ButtonFactory::CreateEqualsButton(this);
	AC = ButtonFactory::CreateACButton(this);
	C = ButtonFactory::CreateCButton(this);
	decimal = ButtonFactory::CreateDecimalButton(this);
	negative = ButtonFactory::CreateNegativeButton(this);

	//number1 = new wxButton(this, ID_NUMBER_1, "1", wxPoint(10, 350), wxSize(50, 50));
	//number2 = new wxButton(this, ID_NUMBER_2, "2", wxPoint(60, 350), wxSize(50, 50));
	//number3 = new wxButton(this, ID_NUMBER_3, "3", wxPoint(110, 350), wxSize(50, 50));
	//number4 = new wxButton(this, ID_NUMBER_4, "4", wxPoint(10, 300), wxSize(50, 50));
	//number5 = new wxButton(this, ID_NUMBER_5, "5", wxPoint(60, 300), wxSize(50, 50));
	//number6 = new wxButton(this, ID_NUMBER_6, "6", wxPoint(110, 300), wxSize(50, 50));
	//number7 = new wxButton(this, ID_NUMBER_7, "7", wxPoint(10, 250), wxSize(50, 50));
	//number8 = new wxButton(this, ID_NUMBER_8, "8", wxPoint(60, 250), wxSize(50, 50));
	//number9 = new wxButton(this, ID_NUMBER_9, "9", wxPoint(110, 250), wxSize(50, 50));
	// c.) Binary Operators: +, -, *, /, % (as modulo)
	//add = new wxButton(this, ID_ADD, "+", wxPoint(160, 350), wxSize(50, 50));
	//sub = new wxButton(this, ID_SUB, "-", wxPoint(210, 350), wxSize(50, 50));
	//mult = new wxButton(this, ID_MULT, "*", wxPoint(160, 300), wxSize(50, 50));
	//div = new wxButton(this, ID_DIV, "/", wxPoint(210, 300), wxSize(50, 50));
	//mod = new wxButton(this, ID_MOD, "mod", wxPoint(210, 400), wxSize(50, 50));
	//
	// d.) Unary Operators: sin, cos, tan (rads and/or deg)
	//sin = new wxButton(this, ID_SIN, "sin(x)", wxPoint(60, 200), wxSize(50, 50));
	//cos = new wxButton(this, ID_COS, "cos(x)", wxPoint(110, 200), wxSize(50, 50));
	//tan = new wxButton(this, ID_TAN, "tan(x)", wxPoint(160, 200), wxSize(50, 50));
	// e.) Equals: = 
	//equals = new wxButton(this, ID_EQUALS, "=", wxPoint(160, 400), wxSize(50, 50));
	// f.) Clear 
	//AC = new wxButton(this, ID_AC, "AC", wxPoint(210, 250), wxSize(50, 50));
	// g.) Backspace/delete
	//C = new wxButton(this, ID_C, "C", wxPoint(160, 250), wxSize(50, 50));
	// h.) Decimal (adds decimal point to text control)
	//decimal = new wxButton(this, ID_DECIMAL, ".", wxPoint(60, 400), wxSize(50, 50));
	// i.) Negative (adds a negative symbol to the text control)
	//negative = new wxButton(this, ID_NEGATIVE, "-(x)", wxPoint(110, 400), wxSize(50, 50));

}
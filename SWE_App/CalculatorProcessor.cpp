#include "CalculatorProcessor.h"
#include <cmath>

// create class
///

CalculatorProcessor* CalculatorProcessor::instance = nullptr;

// constructor
CalculatorProcessor::CalculatorProcessor()
{
}

// destructor
CalculatorProcessor::~CalculatorProcessor()
{
}

CalculatorProcessor* CalculatorProcessor::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new CalculatorProcessor();
	}
	return instance;
}

double CalculatorProcessor::Calculate(wxString expression)
{
	// validate
	if (!ValidateExpression(expression))
	{
		throw std::invalid_argument("Invalid");
	}

	double result = 0.0;
	if (!EvaluateExpression(expression, result))
	{
		throw std::runtime_error("Evaluation failed");
	}

	return result;
}

// bring over Validate/Eval from Window?
bool CalculatorProcessor::ValidateExpression(const wxString& expression)
{
	if (expression.IsEmpty())
	{
		return false;
	}

	// check for operators at beginning (except minus for negative)
	if (expression[0] == '+' || expression[0] == '*' || expression[0] == '/' || expression[0] == '%')
	{
		return false;
	}

	// if at end
	wxChar lastChar = expression[expression.Length() - 1];
	if (lastChar == '+' || lastChar == '-' || lastChar == '*' || lastChar == '/' || lastChar == '%' || lastChar == '.')
	{
		return false;
	}

	// check for consecutive operator and multiple decimals
	bool lastWasOperator = false;
	bool lastWasDecimal = false;

	for (size_t i = 0; i < expression.Length(); i++)
	{
		wxChar c = expression[i];
		bool isOperator = (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');

		// consecutive decimals
		if (c == '.')
		{
			if (lastWasDecimal || lastWasOperator)
			{
				return false;

				lastWasDecimal = true;
			}
			else if (isOperator)
			{
				// reset decimal tracking
				lastWasDecimal = false;

				// check for multiple consecutive operators
				// ALLOW minus after operator
				if (lastWasOperator && c != '-')
				{
					return false;

					// don't allow two minuses in a row
					if (lastWasOperator && c == '-' && i > 0 && expression[i - 1] == '-')
					{
						return false;

						lastWasOperator = true;
					}
					else if (wxIsdigit(c))
					{
						lastWasOperator = false;
						lastWasDecimal = false;
					}
					else if (c == 's' || c == 'c' || c == 't')
					{
						// check if sin/cos/tan
						if (i + 2 < expression.Length())
						{
							wxString trigFunc = expression.Mid(i, 3);
							if (trigFunc == "sin" || trigFunc == "cos" || trigFunc == "tan")
							{
								// 1 2 skip a few
								i += 2;
								lastWasOperator = false;
								lastWasDecimal = false;
								continue;
							}
						}
						return false;
					}
					else if (c != 'c')
					{
						return false;
					}
				}
			}
			return true;
		}
	}
}

bool CalculatorProcessor::EvaluateExpression(wxString expression, double& result)
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
}
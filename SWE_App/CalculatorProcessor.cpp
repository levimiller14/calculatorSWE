#include "CalculatorProcessor.h"
#include <cmath>
#include <vector>
#include <stack>
#include <stdexcept>

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
	// updated logic Shunting Alg
	// validation check 
	if (expression.IsEmpty())
	{
		throw std::invalid_argument("Empty expression");
	}

	try
	{
		// tokenize
		std::vector<wxString> tokens = Tokenize(expression);

		// convert to postfix (Shunting)
		std::vector<wxString> postfix = InfixToPostfix(tokens);

		// evaluate postfix expression
		double result = EvaluatePostfix(postfix);
		
		return result;
	}
	catch (const std::exception& e)
	{
		//wxMessageBox(e.what());
		throw std::runtime_error("Calculation error");
	}

	//// validate
	//if (!ValidateExpression(expression))
	//{
	//	throw std::invalid_argument("Invalid");
	//}
	//
	//double result = 0.0;
	//if (!EvaluateExpression(expression, result))
	//{
	//	throw std::runtime_error("Evaluation failed");
	//}
	//
	//return result;
}

// Shunting Yard algorithm now handles 
//// bring over Validate/Eval from Window?
//bool CalculatorProcessor::ValidateExpression(const wxString& expression)
//{
//	if (expression.IsEmpty())
//	{
//		return false;
//	}
//
//	// check for operators at beginning (except minus for negative)
//	if (expression[0] == '+' || expression[0] == '*' || expression[0] == '/' || expression[0] == '%')
//	{
//		return false;
//	}
//
//	// if at end
//	wxChar lastChar = expression[expression.Length() - 1];
//	if (lastChar == '+' || lastChar == '-' || lastChar == '*' || lastChar == '/' || lastChar == '%' || lastChar == '.')
//	{
//		return false;
//	}
//
//	// check for consecutive operator and multiple decimals
//	bool lastWasOperator = false;
//	bool lastWasDecimal = false;
//
//	for (size_t i = 0; i < expression.Length(); i++)
//	{
//		wxChar c = expression[i];
//		bool isOperator = (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
//
//		// consecutive decimals
//		if (c == '.')
//		{
//			if (lastWasDecimal || lastWasOperator)
//			{
//				return false;
//
//				lastWasDecimal = true;
//			}
//			else if (isOperator)
//			{
//				// reset decimal tracking
//				lastWasDecimal = false;
//
//				// check for multiple consecutive operators
//				// ALLOW minus after operator
//				if (lastWasOperator && c != '-')
//				{
//					return false;
//
//					// don't allow two minuses in a row
//					if (lastWasOperator && c == '-' && i > 0 && expression[i - 1] == '-')
//					{
//						return false;
//
//						lastWasOperator = true;
//					}
//					else if (wxIsdigit(c))
//					{
//						lastWasOperator = false;
//						lastWasDecimal = false;
//					}
//					else if (c == 's' || c == 'c' || c == 't')
//					{
//						// check if sin/cos/tan
//						if (i + 2 < expression.Length())
//						{
//							wxString trigFunc = expression.Mid(i, 3);
//							if (trigFunc == "sin" || trigFunc == "cos" || trigFunc == "tan")
//							{
//								// 1 2 skip a few
//								i += 2;
//								lastWasOperator = false;
//								lastWasDecimal = false;
//								continue;
//							}
//						}
//						return false;
//					}
//					else if (c != 'c')
//					{
//						return false;
//					}
//				}
//			}
//			return true;
//		}
//	}
//}
//
//bool CalculatorProcessor::EvaluateExpression(wxString expression, double& result)
//{
//
//	const double pidiv180 = 3.14159265359 / 180;
//
//	try
//	{
//		for (int i = 1; i < expression.Length() - 2; i++)
//		{
//			//check for digits before trig 
//			if (wxIsdigit(expression[i - 1]))
//			{
//				if (expression.Mid(i, 3) == "sin" || expression.Mid(i, 3) == "cos" || expression.Mid(i, 3) == "tan")
//				{
//					// handle mult between value and trig
//					expression = expression.Mid(0, i) + "*" + expression.Mid(i);
//					break;
//				}
//			}
//		}
//
//		// FIND OPERATOR POSITION
//		wxString op = "";
//		int opPos = -1;
//
//		for (int i = 0; i < expression.Length(); i++)
//		{
//			wxChar c = expression[i];
//			if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
//			{
//				op = c;
//				opPos = i;
//				break;
//			}
//		}
//
//		// If found - Binary
//		if (opPos != -1)
//		{
//			wxString leftStr = expression.Mid(0, opPos);
//			wxString rightStr = expression.Mid(opPos + 1);
//
//			if (leftStr.IsEmpty() || rightStr.IsEmpty())
//				return false;
//
//			double num1 = 0;
//			double num2 = 0;
//
//			// Evaluate LEFT SIDE
//			if (leftStr.StartsWith("sin"))
//			{
//				wxString numStr = leftStr.Mid(3);
//				double angle;
//				if (numStr.IsEmpty() || !numStr.ToDouble(&angle))
//					return false;
//				num1 = std::sin(angle * pidiv180);
//			}
//			else if (leftStr.StartsWith("cos"))
//			{
//				wxString numStr = leftStr.Mid(3);
//				double angle;
//				if (numStr.IsEmpty() || !numStr.ToDouble(&angle))
//					return false;
//				num1 = std::cos(angle * pidiv180);
//			}
//			else if (leftStr.StartsWith("tan"))
//			{
//				wxString numStr = leftStr.Mid(3);
//				double angle;
//				if (numStr.IsEmpty() || !numStr.ToDouble(&angle))
//					return false;
//				num1 = std::tan(angle * pidiv180);
//			}
//			else
//			{
//				num1 = std::stod(leftStr.ToStdString());
//			}
//			// RIGHT SIDE
//			if (rightStr.StartsWith("sin"))
//			{
//				wxString numStr = rightStr.Mid(3);
//				double angle;
//				if (numStr.IsEmpty() || !numStr.ToDouble(&angle))
//					return false;
//				num2 = std::sin(angle * pidiv180);
//			}
//			else if (rightStr.StartsWith("cos"))
//			{
//				wxString numStr = rightStr.Mid(3);
//				double angle;
//				if (numStr.IsEmpty() || !numStr.ToDouble(&angle))
//					return false;
//				num2 = std::cos(angle * pidiv180);
//			}
//			else if (rightStr.StartsWith("tan"))
//			{
//				wxString numStr = rightStr.Mid(3);
//				double angle;
//				if (numStr.IsEmpty() || !numStr.ToDouble(&angle))
//					return false;
//				num2 = std::tan(angle * pidiv180);
//			}
//			else
//			{
//				num2 = std::stod(rightStr.ToStdString());
//			}
//
//			// perform OPERATION
//			if (op == "+")
//				result = num1 + num2;
//			else if (op == "-")
//				result = num1 - num2;
//			else if (op == "*")
//				result = num1 * num2;
//			else if (op == "/")
//			{
//				if (num2 == 0)
//					return false;
//				result = num1 / num2;
//			}
//			else if (op == "%")
//			{
//				if (num2 == 0)
//					return false;
//				result = fmod(num1, num2);
//			}
//			else
//				return false;
//
//			return true;
//		}
//		else
//		{
//			// NO OPERATOR just trig function/number
//			if (expression.StartsWith("sin"))
//			{
//				wxString numStr = expression.Mid(3);
//				double angle;
//				if (numStr.IsEmpty() || !numStr.ToDouble(&angle))
//					return false;
//				result = std::sin(angle * pidiv180);
//				return true;
//			}
//			else if (expression.StartsWith("cos"))
//			{
//				wxString numStr = expression.Mid(3);
//				double angle;
//				if (numStr.IsEmpty() || !numStr.ToDouble(&angle))
//					return false;
//				result = std::cos(angle * pidiv180);
//				return true;
//			}
//			else if (expression.StartsWith("tan"))
//			{
//				wxString numStr = expression.Mid(3);
//				double angle;
//				if (numStr.IsEmpty() || !numStr.ToDouble(&angle))
//					return false;
//				result = std::tan(angle * pidiv180);
//				return true;
//			}
//			else
//			{
//				result = std::stod(expression.ToStdString());
//				return true;
//			}
//		}
//	}
//	catch (const std::invalid_argument&)
//	{
//		return false;
//	}
//	catch (const std::out_of_range&)
//	{
//		return false;
//	}
//	// "CATCH ALL"
//	catch (...)
//	{
//		return false;
//	}
//}

// SHUNTING
// break expression into individual tokens (number/operator/func)
std::vector<wxString> CalculatorProcessor::Tokenize(const wxString& expression)
{
	std::vector<wxString> tokens;
	wxString currentToken = "";

	for (size_t i = 0; i < expression.Length(); i++)
	{
		wxChar c = expression[i];

		// skips empty spaces
		if (c == ' ')
		{
			if (!currentToken.IsEmpty())
			{
				tokens.push_back(currentToken);
				currentToken = "";
			}
			continue;
		}

		// check for operators
		if (c == '+' || c == '*' || c == '/' || c == '%')
		{
			if (!currentToken.IsEmpty())
			{
				tokens.push_back(currentToken);
				currentToken = "";
			}
			tokens.push_back(wxString(c));
		}
		// handle minus (subtraction and/or negative)
		else if (c == '-')
		{
			//if minus is at start or AFTER operator, negative sign
			if (i == 0 || IsOperator(wxString(expression[i - 1])))
			{
				currentToken += c;
			}
			else
			{
				// subtraction
				if (!currentToken.IsEmpty())
				{
					tokens.push_back(currentToken);
					currentToken = "";
				}
				tokens.push_back(wxString(c));
			}
		}
		// decimal check
		else if (c == '.')
		{
			currentToken += c;
		}
		// digits check
		else if (wxIsdigit(c))
		{
			currentToken += c;
		}
		// letters (sin/cos/tan)
		else if (wxIsalpha(c))
		{
			currentToken += c;

			// trig function completed?
			if (currentToken == "sin" || currentToken == "cos" || currentToken == "tan")
			{
				tokens.push_back(currentToken);
				currentToken = "";
			}
		}
	}
	// add last token if available
	if (!currentToken.IsEmpty())
	{
		tokens.push_back(currentToken);
	}
	return tokens;
}

// convert tokens to postfix notation w respect to precedence
std::vector<wxString> CalculatorProcessor::InfixToPostfix(const std::vector<wxString>& tokens)
{
	std::vector<wxString> output;
	std::stack<wxString> operators;

	for (const wxString& token : tokens)
	{
		// if number, add to output
		if (IsNumber(token))
		{
			output.push_back(token);
		}
		// function, push to operator stack
		else if (IsFunction(token))
		{
			operators.push(token);
		}
		// operator
		else if (IsOperator(token))
		{
			// pop op w higher or equal precedence
			while (!operators.empty())
			{
				wxString top = operators.top();
				if ((IsOperator(top) || IsFunction(top)) && GetPrecedence(top) >= GetPrecedence(token))
				{
					output.push_back(top);
					operators.pop();
				}
				else
				{
					break;
				}
			}
			operators.push(token);
		}
	}
	// pop remaining
	while (!operators.empty())
	{
		output.push_back(operators.top());
		operators.pop();
	}
	return output;
}

// evaluate postfix expression to get final result
double CalculatorProcessor::EvaluatePostfix(const std::vector<wxString>& postfix)
{
	std::stack<double> values;
	const double pidiv180 = 3.14159265359 / 180.0;

	for (const wxString& token : postfix)
	{
		// if number , push to stack
		if (IsNumber(token))
		{
			double value;
			token.ToDouble(&value);
			values.push(value);
		}
		// trig function, top of stack
		else if (IsFunction(token))
		{
			if (values.empty())
			{
				throw std::runtime_error("Invalid expression");
			}

			double arg = values.top();
			values.pop();

			double result;
			if (token == "sin")
			{
				result = std::sin(arg * pidiv180);
			}
			else if (token == "cos")
			{
				result = std::cos(arg * pidiv180);
			}
			else if (token == "tan")
			{
				result = std::tan(arg * pidiv180);
			}
			else
			{
				throw std::runtime_error("Unkown function");
			}

			values.push(result);

		}
		// operator, apply to top 2
		else if (IsOperator(token))
		{
			if (values.size() < 2)
			{
				throw std::runtime_error("Invalid expression");
			}
			double right = values.top();
			values.pop();
			double left = values.top();
			values.pop();

			double result;
			if (token == "+")
			{
				result = left + right;
			}
			else if (token == "-")
			{
				result = left - right;
			}
			else if (token == "*")
			{
				result = left * right;
			}
			else if (token == "/")
			{
				if (right == 0)
				{
					throw std::runtime_error("Division by zero");
				}
				result = left / right;
			}
			else if (token == "%")
			{
				if (right == 0)
				{
					throw std::runtime_error("Mod by zero");
				}
				result = fmod(left, right);
			}
			else
			{
				throw std::runtime_error("Uknown operator");
			}
			values.push(result);
		}
	}
	// w last value
	if (values.empty())
	{
		throw std::runtime_error("No values on stack");
	}
	if (values.size() > 1)
	{
		throw std::runtime_error(wxString::Format("Too many values: %zu", values.size()).ToStdString());
	}
	return values.top();
}

// is the "token" an operator
bool CalculatorProcessor::IsOperator(const wxString& token)
{
	return (token == "+" || token == "-" || token == "*" || token == "/" || token == "%");
}

// a trig function?
bool CalculatorProcessor::IsFunction(const wxString& token)
{
	return (token == "sin" || token == "cos" || token == "tan");
}

// number?
bool CalculatorProcessor::IsNumber(const wxString& token)
{
	if (token.IsEmpty())
	{
		return false;
	}
	// negative or decima?
	double temp;
	return token.ToDouble(&temp);
}

// higher number = precedence
int CalculatorProcessor::GetPrecedence(const wxString& op)
{
	if (op == "sin" || op == "cos" || op == "tan")
	{
		// highest
		return 3;
	}
	else if (op == "*" || op == "/" || op == "%")
	{
		// mid
		return 2;
	}
	else if (op == "+" || op == "-")
	{
		// low
		return 1;
	}
	else
	{
		// not an operator
		return 0;
	}
}

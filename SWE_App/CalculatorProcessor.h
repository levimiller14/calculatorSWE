#pragma once
#include "wx/wx.h"
#include <vector>
#include <stack>
#include <string>

//
// create class
class CalculatorProcessor
{
private:
	// Singleton private constructor
	CalculatorProcessor();

	// private destructor
	~CalculatorProcessor();

	// delete copy constructor and assignment operator
	CalculatorProcessor(const CalculatorProcessor&) = delete;
	CalculatorProcessor& operator=(const CalculatorProcessor&) = delete;

	// single instance pointer
	static CalculatorProcessor* instance;

	// covered by shunting logic now
	// private helper methods
	//bool ValidateExpression(const wxString& expression);
	//bool EvaluateExpression(wxString expression, double& result);

	// Shunting Yard
	std::vector<wxString> Tokenize(const wxString& expression);
	std::vector<wxString> InfixToPostfix(const std::vector<wxString>& tokens);
	double EvaluatePostfix(const std::vector<wxString>& postfix);

	// helpers
	bool IsOperator(const wxString& token);
	bool IsFunction(const wxString& token);
	bool IsNumber(const wxString& token);
	int GetPrecedence(const wxString& op);

public:
	// GET single instance
	static CalculatorProcessor* GetInstance();

	// main calc method
	double Calculate(wxString epxression);
};


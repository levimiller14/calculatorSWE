#pragma once
#include "wx/wx.h"

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

	// private helper methods
	bool ValidateExpression(const wxString& expression);
	bool EvaluateExpression(wxString expression, double& result);

public:
	// GET single instance
	static CalculatorProcessor* GetInstance();

	// main calc method
	double Calculate(wxString epxression);
};


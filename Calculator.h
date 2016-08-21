#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <string>
#include <stack>
#include <vector>
#include <sstream> // for istringstream
#include "Exception.h"
#include "PolishNotation.h"


class Calculator
{
private:
	float answer;
	std::stack<float> stackFloat; // for Revers Polish Notation.
	PolishNotation* polishNotation;

public:
	Calculator();
	void SetExpression(std::string expression);
	float GetAnswer(); // getr for answer
	~Calculator();

private:
	void Calculate(std::string revPolNot);
	void GetOperator(std::string str);
	void PopStack(float& num);
	void CheckDots(std::vector<std::string>& vectorStr);
};

#endif
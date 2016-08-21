
#include "Calculator.h"
#include "Check.h"
Calculator::Calculator()
{
	polishNotation = new PolishNotation();
}

void Calculator::SetExpression(std::string expression)
{
	polishNotation->CleanStr();
	std::string revPolNot = polishNotation->DoRevPolNot(expression);
	Calculate(revPolNot);
}

Calculator::~Calculator()
{
	delete polishNotation;
}

// calculation expression for Polish Notation
void Calculator::Calculate(std::string revPolNot)
{
	// parsing the string at whitespace
	std::vector<std::string> vectorStr;
	std::istringstream iss(revPolNot);
	std::string temp;
	while (iss >> temp)
	{
		vectorStr.push_back(temp); // get vector with elements without whitespace
	}

	CheckDots(vectorStr);

	for (size_t i = 0; i < vectorStr.size(); i++)
	{
		try
		{
			float temp = stof(vectorStr.at(i));
			stackFloat.push(temp);
		}
		catch (...)
		{
			if (Check::IsOperator(vectorStr.at(i).at(0)))
			{
				std::string a = vectorStr.at(i);
				GetOperator(vectorStr.at(i));
			}
		}
	}

	// if the stack have one element, this is answer
	if (stackFloat.size() == 1)
	{
		answer = stackFloat.top();
		stackFloat.pop();
	}
	else
	{
		while (!stackFloat.empty())
		{
			stackFloat.pop();
		}
		throw (Exception("not enough operators!"));
	}
}

// get operator in the float
void Calculator::GetOperator(std::string str)
{
	int encodedData = (int)(str.at(0)); // ascii code of elem
	try
	{
		switch (encodedData)
		{
		case 42: // " * "
		{
			float a, b;
			PopStack(b);
			PopStack(a);
			stackFloat.push(a*b);
			break;
		}
		case 43:// " + "
		{
			float a, b;
			PopStack(b);
			PopStack(a);
			stackFloat.push(a + b);
			break;
		}
		case 45:// " - " 
		{
			float a, b;
			PopStack(b);
			PopStack(a);
			stackFloat.push(a - b);
			break;
		}
		case 47:// " / "
		{
			float a, b;
			PopStack(b);
			PopStack(a);
			if (b == 0) throw (Exception("divide by 0 is forbidden!"));
			else stackFloat.push(a / b);
			break;
		}
		default:
			throw (Exception("missing an closing bracket"));
		}
	}
	catch (Exception& e)
	{
		throw (Exception(e.what()));
	}
}

// pulls out a stack element
void Calculator::PopStack(float& num)
{
	if (!stackFloat.empty())
	{
		num = stackFloat.top();
		stackFloat.pop();
	}
	else
	{
		throw (Exception("not enough operands!"));
	}
}

// error checking with dots / commas
void Calculator::CheckDots(std::vector<std::string>& vectorStr)
{
	int counter;
	size_t pos; // deleted item position

	for (size_t i = 0; i < vectorStr.size(); i++)
	{
		counter = 0;
		// replase the first "," on "."
		if ((pos = vectorStr.at(i).find(",")) != vectorStr.at(i).npos)
			vectorStr.at(i).replace(pos, 1, ".");

		// if we found "," or "." we increase the counter
		for (size_t j = 0; j < vectorStr.at(i).length(); j++)
			if (vectorStr.at(i).at(j) == '.' || vectorStr.at(i).at(j) == ',')
			{
				counter++;
				if (counter > 1) throw (Exception("incorrect expression"));
			}
	}
}

// the output answer
float Calculator::GetAnswer() 
{ 
	return answer; 
}


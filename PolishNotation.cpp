#include "PolishNotation.h"
#include "Check.h"
#include "Exception.h"


PolishNotation::PolishNotation()
{
}

PolishNotation::~PolishNotation()
{
}

std::string PolishNotation::DoRevPolNot(std::string expression)
{
	for (size_t i = 0; i < expression.length(); i++)
	{
		try
		{
			if (expression.at(i) == ' ')
			{
				revPolNot += ' ';
				continue;
			}
			// if this is the operator, write it depending on the priority
			if (Check::IsOperator(expression.at(i)))
			{
				revPolNot += ' ';

				// BEGIN_negative_values_processing --->
				if (i > 0 && expression.at(i - 1) == '(' && (expression.at(i) == '+' || expression.at(i) == '-'))
				{
					revPolNot += expression.at(i);
					continue;
				}
				// <--- END_negative_values_processing

				// BEGIN_two_consecutive_operands_processing --->
				if (i < expression.length() - 1
					&& Check::DoCheck(expression.at(i), "+-*/")
					&& Check::DoCheck(expression.at(i + 1), "+-*/"))
				{
					throw (Exception("too many operators"));
				}
				// <--- END_two_consecutive_operands_processing

				SetPriority(std::string(1, expression.at(i)));
			}

			// if this is number, add to Polish Notation 
			else if (Check::IsNumber((expression.at(i))))
			{
				revPolNot += expression.at(i);
			}
			else
			{
				std::string error;
				do
				{
					error += expression.at(i++); //add elem to "string error"
				} while (i < expression.length() && !Check::IsNumber(expression.at(i)) &&
					!Check::IsOperator(expression.at(i)));
				throw (Exception(error));
			}
		}
		catch (Exception& e) { throw Exception(e.what()); }
		catch (...) {}
	}

	while (!stackString.empty())
	{
		revPolNot += " ";
		revPolNot += stackString.top();
		stackString.pop();
	}

	return revPolNot;
}

void PolishNotation::SetPriority(std::string str)
{
	if (str == "(")
	{
		stackString.push(str);
		return;
	}
	if (str == ")")
	{
		while (true)
		{
			if (stackString.empty())
			{
				throw (Exception("missing an opening bracket"));
			}
			else if (stackString.top() == "(")
			{
				stackString.pop();
				return;
			}
			else
			{
				// if the node isn't "(" and the stack isn't empty, 
				// we pull out the elements
				revPolNot += stackString.top();
				revPolNot += " ";
				stackString.pop();
			}
		}
	}
	if (str == "+" || str == "-")
	{
		while (true)
		{
			// for the first negative element (beginning of expression)
			if ((stackString.empty() || stackString.top() == "(") && revPolNot == " ")
			{
				revPolNot += str;
				return;
			}

			if (stackString.empty() || stackString.top() == "(")
			{
				stackString.push(str);
				return;
			}
			else
			{
				// if the node isn't "(" and the stack isn't empty, 
				// we pull out the elements
				revPolNot += stackString.top();
				revPolNot += " ";
				stackString.pop();
			}
		}
	}
	else if (str == "*" || str == "/")
	{
		while (true)
		{
			if (stackString.empty() ||
				stackString.top() == "+" ||
				stackString.top() == "-" ||
				stackString.top() == "(")
			{
				stackString.push(str);
				return;
			}
			else
			{
				// if the node isn't "(", "+", "-", and the stack isn't empty, 
				// we pull out the elements
				revPolNot += stackString.top();
				revPolNot += " ";
				stackString.pop();
			}
		}
	}
}

void PolishNotation::CleanStr()
{
	revPolNot = "";
}

#include "Calculator.h"
#include <iostream>


/*
App - Calculator.
 The method of calculation - Revers Polish Notation.
 More details about the algorithm https://habrahabr.ru/post/100869/

 This calculator check error like:
 "--1 + 2" double or more operands
 "12,,1 - 1"  double or more commas
 "12..1 - 1" double or more dots
 "((12.1 - 1)" double or more open parenthesis
 "(12.1 - 1))" double or more closing parenthesis
 "asd 12.1 - 1" incorrect elements
 "1+1" without whitespaces
 "1  +    1" one or more whitespaces

 Author: Sizih Vladimir. 2016
 */


int main() {
	std::cout << "\nWelcome! To exit, type \"exit\". \n" << std::endl
			  << "Enter the expression: ";
	
	
	std::cout.setf(std::ios::fixed, std::ios::floatfield); // floatfield set to fixed
	std::cout.precision(2);

	std::string _expression; // stores the expression
	Calculator* calculator = new Calculator(); // the calculation expression

	std::getline(std::cin, _expression);
	while (_expression.compare("exit"))
	{
		try {
			calculator->SetExpression(_expression);
			std::cout << "Answer: " << calculator->GetAnswer() << std::endl;
		}
		catch (Exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << "Enter the expression: ";
		std::getline(std::cin, _expression);
	}
	delete calculator;
	return 0;
}
# Calculator
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

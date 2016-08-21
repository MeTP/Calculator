
#include <string>
#include <stack>

class PolishNotation
{
private:
	std::string	revPolNot;
	std::stack<std::string> stackString; // for Revers Polish Notation.
	void SetPriority(std::string str);


public:
	PolishNotation();
	~PolishNotation();
	std::string DoRevPolNot(std::string expression); // get Polish Notation
	void CleanStr();
};


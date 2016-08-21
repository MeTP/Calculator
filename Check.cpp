#include "Check.h"

Check::Check()
{
}


Check::~Check()
{
}

bool Check::DoCheck(const char elem, const std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (elem == str.at(i)) return true;
	}
	return false;
}

bool Check::IsNumber(char elem)
{
	return DoCheck(elem, "0123456789.,");
}

bool Check::IsOperator(char elem)
{
	return DoCheck(elem, "+-*/()");
}


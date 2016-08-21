
#include <cxxtest/TestSuite.h>

#include "Calculator.h"
#include "Check.h"

class  CalculatorTest : public CxxTest::TestSuite
{
public:
	void testSetExpression()
	{
		TS_TRACE("Starting Calculator::SetExpression test");

		Calculator* calculator = new Calculator();

		calculator->SetExpression("1+1");
		TS_ASSERT_EQUALS(calculator->GetAnswer(), 2);

		calculator->SetExpression(" 1 +    1");
		TS_ASSERT_EQUALS(calculator->GetAnswer(), 2);

		calculator->SetExpression("10/2");
		TS_ASSERT_EQUALS(calculator->GetAnswer(), 5);

		calculator->SetExpression("5*5");
		TS_ASSERT_EQUALS(calculator->GetAnswer(), 25);

		calculator->SetExpression("10-5");
		TS_ASSERT_EQUALS(calculator->GetAnswer(), 5);

		calculator->SetExpression("-1-1");
		TS_ASSERT_EQUALS(calculator->GetAnswer(), -2);

		calculator->SetExpression("1-(-1)");
		TS_ASSERT_EQUALS(calculator->GetAnswer(), 2);

		calculator->SetExpression("((1+2)-(3-2))/2");
		TS_ASSERT_EQUALS(calculator->GetAnswer(), 1);


		try
		{
			calculator->SetExpression("--1");
		}
		catch (Exception &e)
		{
			TS_ASSERT_EQUALS(std::string(e.what()), "too many operators");
		}

		try
		{
			calculator->SetExpression("2..1");
		}
		catch (Exception &e)
		{
			TS_ASSERT_EQUALS(std::string(e.what()), "incorrect expression");
		}

		try
		{
			calculator->SetExpression("2,,1");
		}
		catch (Exception &e)
		{
			TS_ASSERT_EQUALS(std::string(e.what()), "incorrect expression");
		}

		try
		{
			calculator->SetExpression("((1+1)");
		}
		catch (Exception &e)
		{
			TS_ASSERT_EQUALS(std::string(e.what()), "missing an closing bracket");
		}

		try
		{
			calculator->SetExpression("(1+1))");
		}
		catch (Exception &e)
		{
			TS_ASSERT_EQUALS(std::string(e.what()), "missing an opening bracket");
		}

		try
		{
			calculator->SetExpression("1 + asd");
		}
		catch (Exception &e)
		{
			TS_ASSERT_EQUALS(std::string(e.what()), "asd");
		}

		TS_TRACE("Finishing Calculator::SetExpression test");
	}
};

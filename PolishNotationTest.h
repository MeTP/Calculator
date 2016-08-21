#include <cxxtest/TestSuite.h>

#include "PolishNotation.h"
#include "Check.h"
#include "Exception.h"


class PolishNotationTest : public CxxTest::TestSuite
{
private:
	PolishNotation* polishNotation = new PolishNotation();
public:

	void testDoRevPolNot()
	{
		TS_ASSERT_EQUALS(polishNotation->DoRevPolNot("3 * 2"), "3   2 *");
		polishNotation->CleanStr();
		TS_ASSERT_EQUALS(polishNotation->DoRevPolNot("3 + 2"), "3   2 +");
		polishNotation->CleanStr();
		TS_ASSERT_EQUALS(polishNotation->DoRevPolNot("10 / 2"), "10   2 /");
		polishNotation->CleanStr();
		TS_ASSERT_EQUALS(polishNotation->DoRevPolNot("10 - 5"), "10   5 -");
		polishNotation->CleanStr();
		TS_ASSERT_EQUALS(polishNotation->DoRevPolNot("(-1)+1"), "  -1  1 +");
		polishNotation->CleanStr();
		TS_ASSERT_EQUALS(polishNotation->DoRevPolNot("-1+2"), " -1 2 +");
		polishNotation->CleanStr();
		TS_ASSERT_EQUALS(polishNotation->DoRevPolNot("1+(-2)"), "1   -2  +");
		polishNotation->CleanStr();
		TS_ASSERT_EQUALS(polishNotation->DoRevPolNot("1.1 + 0.9"), "1.1   0.9 +");
		polishNotation->CleanStr();
		TS_ASSERT_EQUALS(polishNotation->DoRevPolNot("1,1 + 0,9"), "1,1   0,9 +");
		polishNotation->CleanStr();

		try
		{
			polishNotation->DoRevPolNot("--1");
		}
		catch (Exception &e)
		{
			TS_ASSERT_EQUALS(e.what(), "too many operators");
		}

		try
		{
			polishNotation->DoRevPolNot("2..1");
		}
		catch (Exception &e)
		{
			TS_ASSERT_EQUALS(e.what(), "incorrect expression");
		}

		try
		{
			polishNotation->DoRevPolNot("2,,1");
		}
		catch (Exception &e)
		{
			TS_ASSERT_EQUALS(e.what(), "incorrect expression");
		}

		try
		{
			polishNotation->DoRevPolNot("((1+1)");
		}
		catch (Exception &e)
		{
			TS_ASSERT_EQUALS(e.what(), "missing an closing bracket");
		}

		try
		{
			polishNotation->DoRevPolNot("(1+1))");
		}
		catch (Exception &e)
		{
			TS_ASSERT_EQUALS(e.what(), "missing an opening bracket");
		}

		try
		{
			polishNotation->DoRevPolNot("1 + asd");
		}
		catch (Exception &e)
		{
			TS_ASSERT_EQUALS(e.what(), "asd");
		}

		TS_ASSERT_THROWS_NOTHING(polishNotation->DoRevPolNot("3 * 2"));
		TS_ASSERT_THROWS_NOTHING(polishNotation->DoRevPolNot("3 + 2"));
		TS_ASSERT_THROWS_NOTHING(polishNotation->DoRevPolNot("10 / 2"));
		TS_ASSERT_THROWS_NOTHING(polishNotation->DoRevPolNot("10 - 5"));
		TS_ASSERT_THROWS_NOTHING(polishNotation->DoRevPolNot("(-1)+1"));
		TS_ASSERT_THROWS_NOTHING(polishNotation->DoRevPolNot("-1+2"));
		TS_ASSERT_THROWS_NOTHING(polishNotation->DoRevPolNot("1+(-2)"));
		TS_ASSERT_THROWS_NOTHING(polishNotation->DoRevPolNot("1.1 + 0.9"));
		TS_ASSERT_THROWS_NOTHING(polishNotation->DoRevPolNot("1,1 + 0,9"));	
	}	
		
};		
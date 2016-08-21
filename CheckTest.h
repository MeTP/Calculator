#include <cxxtest/TestSuite.h>


#include "Check.h"


class CheckTest : public CxxTest::TestSuite
{
public:
	void testDoCheck()
	{
		TS_TRACE("Starting Check::DoCheck test");

		TS_ASSERT_EQUALS(Check::DoCheck('1', "1"), true);
		TS_ASSERT_EQUALS(Check::DoCheck('1', "2"), false);

		TS_TRACE("Finishing Check::DoCheck test");
	}

	void testIsNumber()
	{
		TS_TRACE("Starting Check::IsNumber test");

		TS_ASSERT_EQUALS(Check::IsNumber('1'), true);
		TS_ASSERT_EQUALS(Check::IsNumber('2'), true);
		TS_ASSERT_EQUALS(Check::IsNumber('.'), true);
		TS_ASSERT_EQUALS(Check::IsNumber('a'), false);
		TS_ASSERT_EQUALS(Check::IsNumber('b'), false);
		TS_ASSERT_EQUALS(Check::IsNumber('/'), false);
		
		TS_TRACE("Finishing Check::IsNumber test");
	}

	void testIsOperator()
	{
		TS_TRACE("Starting Check::IsOperator test");

		TS_ASSERT_EQUALS(Check::IsOperator('+'), true);
		TS_ASSERT_EQUALS(Check::IsOperator(')'), true);
		TS_ASSERT_EQUALS(Check::IsOperator('/'), true);
		TS_ASSERT_EQUALS(Check::IsOperator('1'), false);
		TS_ASSERT_EQUALS(Check::IsOperator('a'), false);
		TS_ASSERT_EQUALS(Check::IsOperator('%'), false);

		TS_TRACE("Finishing Check::IsOperator test");
	}

};
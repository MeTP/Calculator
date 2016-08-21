#include <cxxtest/TestSuite.h>

#include "Exception.h"

class ExceptionTest : public CxxTest::TestSuite 
{
public:
	void testWhat()
	{
		TS_TRACE("Starting Exception::what test");
		Exception e("test");
		TS_ASSERT_EQUALS(std::string(e.what()), "test");
		TS_TRACE("Finishing Exception::what test");
	}
};
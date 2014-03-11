#include <boost/test/minimal.hpp>
#include "LocCounter.hpp"

int test_main(int, char *[])
{
	LocCounter locCounter;
	BOOST_CHECK(locCounter.loc_count() == 0);
	return 0;
}

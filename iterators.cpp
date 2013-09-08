#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <deque>
#include "utils.h"
#include "STL_test.h"

static void iterator_adapter()
{
	PS;

	std::deque<std::string> v{"QQ"};

	//std::copy(std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>(), std::front_inserter(v));

	PRINT_ELEMENTS(v);

	PS;
}

static void transform()
{
	PS;
	std::deque<int> coll = { 1, 2, 3, 5, 7, 11, 13, 17, 19 };
	PRINT_ELEMENTS(coll,"initialized: ");

	std::transform(coll.cbegin(), coll.cend(),
				coll.begin(),
				std::negate<int>());
	PRINT_ELEMENTS(coll,"negated: ");

	std::transform(coll.cbegin(), coll.cend(),
				coll.cbegin(),
				coll.begin(),
				std::multiplies<int>());
	PRINT_ELEMENTS(coll,"squared: ");	

	PS;
}

void test_iterator()
{
	iterator_adapter();

	transform();
}
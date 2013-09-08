#include <array>
#include <algorithm>
#include "utils.h"
#include "STL_test.h"

void test_array()
{
	PS;

	std::array<int, 10> a{{11, 22, 33, 44}};
	PRINT_ELEMENTS(a);

	a.back() = 999999;
	*(&a.back()-1) = 100;
	a[a.size()-3] = 42;
	PRINT_ELEMENTS(a);

	std::cout << "sum :" << std::accumulate(a.begin(), a.end(), 0) << std::endl;

	std::transform(a.begin(), a.end(),
				a.begin(),
				std::negate<int>()
				);
	PRINT_ELEMENTS(a);

	PS;
}
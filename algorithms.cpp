#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"
#include "STL_test.h"

void test_algorithm()
{
	PS;

	// create vector with elements from 1 to 6 in arbitrary order
	std::vector<int> coll{ 2, 5, 4, 1, 6, 3 };
	// find and print minimum and maximum elements
	auto minpos = std::min_element(coll.cbegin(),coll.cend());
	std::cout << "min: "  << *minpos << std::endl;
	auto maxpos = std::max_element(coll.cbegin(),coll.cend());
	std::cout << "max: "  << *maxpos << std::endl;
	// sort all elements
	std::sort (coll.begin(), coll.end());
	// find the first element with value 3
	// - no cbegin()/cend() because later we modify the elements pos3 refers to
	auto pos3 = find (coll.begin(), coll.end(), 3); // value
	// reverse the order of the found element with value 3 and all following elements
	std::reverse (pos3, coll.end());
	// print all elements
	std::for_each(coll.begin(), coll.end(),
		[](int elem)
		{
			std::cout << elem << ' ';
		}
		);
	std::cout << std::endl;

	PS;
}
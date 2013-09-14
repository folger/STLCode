#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include "utils.h"
#include "STL_test.h"
using namespace std;
using namespace std::placeholders;

static void test_count()
{
	PSH("test_count");
	
	vector<int> coll;
	int num;
	INSERT_ELEMENTS(coll,1,9);
	PRINT_ELEMENTS(coll,"coll: ");
	// count elements with value 4
	num = count (coll.cbegin(), coll.cend(), // range
	4); // value
	cout << "number of elements equal to 4: " << num << endl;

	// count elements with even value
	num = count_if (coll.cbegin(), coll.cend(), // range
			[](int elem){ // criterion
				return elem%2==0;
			});
	cout << "number of elements with even value: " << num << endl;
	// count elements that are greater than value 4
	num = count_if (coll.cbegin(), coll.cend(), // range
			[](int elem){ // criterion
				return elem>4;
			});
	cout << "number of elements greater than 4: " << num << endl;
	
	PS;
}

static bool absLess (int elem1, int elem2)
{
	return abs(elem1) < abs(elem2);
}

static void test_min_max()
{
	PSH("test_min_max");

	deque<int> coll;
	INSERT_ELEMENTS(coll,2,6);
	INSERT_ELEMENTS(coll,-3,6);
	PRINT_ELEMENTS(coll);

	// process and print minimum and maximum
	cout << "minimum: "
	<< *min_element(coll.cbegin(),coll.cend())
	<< endl;
	cout << "maximum: "
	<< *max_element(coll.cbegin(),coll.cend())
	<< endl;
	// print min and max and their distance using minmax_element()
	auto mm = minmax_element(coll.cbegin(),coll.cend());
	cout << "min: " << *(mm.first) << endl; // print minimum
	cout << "max: " << *(mm.second) << endl; // print maximum
	cout << "distance: " << distance(mm.first,mm.second) << endl;
	// process and print minimum and maximum of absolute values
	cout << "minimum of absolute values: "
	<< *min_element(coll.cbegin(),coll.cend(),
	absLess)
	<< endl;
	cout << "maximum of absolute values: "
	<< *max_element(coll.cbegin(),coll.cend(),
	absLess)
	<< endl;
	
	PS;
}

static void test_find()
{
	PSH("test_find");
	
	vector<int> coll;
	vector<int>::iterator pos;
	INSERT_ELEMENTS(coll,1,9);
	PRINT_ELEMENTS(coll,"coll: ");
	// find first element greater than 3
	pos = find_if (coll.begin(), coll.end(), // range
			bind(greater<int>(),_1,3)); // criterion
	// print its position
	cout << "the "
	<< distance(coll.begin(),pos) + 1
	<< ". element is the first greater than 3" << endl;
	// find first element divisible by 3
	pos = find_if (coll.begin(), coll.end(),
			[](int elem){
				return elem%3==0;
			});
	// print its position
	cout << "the "
	<< distance(coll.begin(),pos) + 1
	<< ". element is the first divisible by 3" << endl;
	// find first element not <5
	pos = find_if_not (coll.begin(), coll.end(),
	bind(less<int>(),_1,5));
	cout << "first value >=5: " << *pos << endl;
	
	PS;
}

void test_algorithm()
{
	PSH("test_algorithm");

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
	
	test_count();
	test_min_max();
	test_find();
}
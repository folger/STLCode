#include <iostream>
#include <vector>
#include <deque>
#include <list>
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

static void test_search_n()
{
	PSH("test_search_n");
	
	deque<int> coll;
	coll = { 1, 2, 7, 7, 6, 3, 9, 5, 7, 7, 7, 3, 6 };
	PRINT_ELEMENTS(coll);
	// find three consecutive elements with value 7
	deque<int>::iterator pos;
	pos = search_n (coll.begin(), coll.end(), // range
	3, // count
	7); // value

	// print result
	if (pos != coll.end()) {
		cout << "three consecutive elements with value 7 "
		<< "start with " << distance(coll.begin(),pos) +1
		<< ". element" << endl;
	}
	else {
		cout << "no four consecutive elements with value 7 found"
		<< endl;
	}
	// find four consecutive odd elements
	pos = search_n (coll.begin(), coll.end(), // range
	4, // count
	0, // value
	[](int elem, int value){ // criterion
		return elem%2==1;
	});
	// print result
	if (pos != coll.end()) {
		cout << "first four consecutive odd elements are: ";
		for (int i=0; i<4; ++i, ++pos) {
			cout << *pos << ' ';
		}
	}
	else {
		cout << "no four consecutive elements with value > 3 found";
	}
	cout << endl;
	
	PS;
}

static bool checkEven (int elem, bool even)
{
	if (even) {
		return elem % 2 == 0;
	}
	else {
		return elem % 2 == 1;
	}
}

static void test_search()
{
	PSH("test_search");

	vector<int> coll;
	INSERT_ELEMENTS(coll,1,9);
	PRINT_ELEMENTS(coll,"coll: ");
	// arguments for checkEven()
	// - check for: ‘‘even odd even’’
	bool checkEvenArgs[3] = { true, false, true };
	// search first subrange in coll
	vector<int>::iterator pos;
	pos = search (coll.begin(), coll.end(), // range
	checkEvenArgs, checkEvenArgs+3, // subrange values
	checkEven); // subrange criterion
	// loop while subrange found
	while (pos != coll.end()) {
		// print position of first element
		cout << "subrange found starting with element "
		<< distance(coll.begin(),pos) + 1
		<< endl;
		// search next subrange in coll
		pos = search (++pos, coll.end(), // range
		checkEvenArgs, checkEvenArgs+3, // subr. values
		checkEven); // subr. criterion
	}
	
	PS;
}

static void test_find_end()
{
	PSH("test_find_end");
	
	deque<int> coll;
	list<int> subcoll;
	INSERT_ELEMENTS(coll,1,7);
	INSERT_ELEMENTS(coll,1,7);
	INSERT_ELEMENTS(subcoll,3,6);
	PRINT_ELEMENTS(coll, "coll: ");
	PRINT_ELEMENTS(subcoll,"subcoll: ");
	//search last occurrence of subcoll in coll
	deque<int>::iterator pos;
	pos = find_end (coll.begin(), coll.end(), //range
	subcoll.begin(), subcoll.end()); //subrange
	// loopwhile subcoll found assubrange of coll
	deque<int>::iterator end(coll.end());
	while (pos != end) {
		// print position of ﬁrst element
		cout << "subcoll found starting with element "
		<< distance(coll.begin(),pos) + 1
		<< endl;
		//search next occurrence of subcoll
		end = pos;
		pos = find_end (coll.begin(), end, //range
		subcoll.begin(), subcoll.end()); //subrange
	}
	
	PS;
}

static void test_find_first_of()
{
	PSH("find_first_of");
	
	vector<int> coll;
	list<int> searchcoll;
	INSERT_ELEMENTS(coll,1,11);
	INSERT_ELEMENTS(searchcoll,3,5);
	PRINT_ELEMENTS(coll, "coll: ");
	PRINT_ELEMENTS(searchcoll,"searchcoll: ");
	//search ﬁrst occurrence of an element of searchcoll in coll
	vector<int>::iterator pos;
	pos = find_first_of (coll.begin(), coll.end(), //range
	searchcoll.begin(), // beginning ofsearch set
	searchcoll.end()); // end ofsearch set

	cout << "first element of searchcoll in coll is element "
	<< distance(coll.begin(),pos) + 1
	<< endl;
	//search last occurrence of an element of searchcoll in coll
	vector<int>::reverse_iterator rpos;
	rpos = find_first_of (coll.rbegin(), coll.rend(), //range
	searchcoll.begin(), // beginning ofsearch set
	searchcoll.end()); // end ofsearch set
	cout << "last element of searchcoll in coll is element "
	<< distance(coll.begin(),rpos.base())
	<< endl;
	
	PS;
}

static bool doubled (int elem1, int elem2)
{
	return elem1 * 2 == elem2;
}

static void test_adjacent_find()
{
	PSH("adjacent_find");
	
	vector<int> coll;
	coll.push_back(1);
	coll.push_back(3);
	coll.push_back(2);
	coll.push_back(4);
	coll.push_back(5);
	coll.push_back(5);
	coll.push_back(0);
	PRINT_ELEMENTS(coll,"coll: ");
	//search ﬁrst two elementswith equal value
	vector<int>::iterator pos;
	pos = adjacent_find (coll.begin(), coll.end());
	if (pos != coll.end()) {
		cout << "first two elements with equal value have position "
		<< distance(coll.begin(),pos) + 1
		<< endl;
	}
	//search ﬁrst two elementsforwhich the second has double the value of the ﬁrst
	pos = adjacent_find (coll.begin(), coll.end(), //range
	doubled); // criterion
	if (pos != coll.end()) {
		cout << "first two elements with second value twice the "
		<< "first have pos. "
		<< distance(coll.begin(),pos) + 1
		<< endl;
	}
	
	PS;
}

static bool bothEvenOrOdd (int elem1, int elem2)
{
	return (elem1 & 1) == (elem2 & 1);
}

static void test_euqal()
{
	PSH("test_euqal");
	
	vector<int> coll1;
	list<int> coll2;
	INSERT_ELEMENTS(coll1,1,7);
	INSERT_ELEMENTS(coll2,3,9);
	PRINT_ELEMENTS(coll1,"coll1: ");
	PRINT_ELEMENTS(coll2,"coll2: ");
	// checkwhether both collections are equal
	if (equal (coll1.begin(), coll1.end(), // ﬁrstrange
				coll2.begin())) { //second range
		cout << "coll1 == coll2" << endl;
	}
	else {
		cout << "coll1 != coll2" << endl;
	}
	// check for corresponding even and odd elements
	if (equal (coll1.begin(), coll1.end(), // ﬁrstrange
				coll2.begin(), //second range
				bothEvenOrOdd)) { // comparison criterion
		cout << "even and odd elements correspond" << endl;
	}
	else {
		cout << "even and odd elements do not correspond" << endl;
	}
	
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
	test_search_n();
	test_search();
	test_find_end();
	test_find_first_of();
	test_adjacent_find();
	test_euqal();
}
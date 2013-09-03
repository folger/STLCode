#include <list>
#include <forward_list>
#include <algorithm>
#include <iterator>
#include "utils.h"
#include "list.h"
using namespace std;

static void printLists (const list<int>& l1, const list<int>& l2)
{
	cout << "list1: ";
	copy (l1.cbegin(), l1.cend(), ostream_iterator<int>(cout," "));
	cout << endl << "list2: ";
	copy (l2.cbegin(), l2.cend(), ostream_iterator<int>(cout," "));
	cout << endl << endl;
}

void test_list()
{
	// create two empty lists
	list<int> list1, list2;
	// fill both lists with elements
	for (int i=0; i<6; ++i) {
	list1.push_back(i);
	list2.push_front(i);
	}
	printLists(list1, list2);
	// insert all elements of list1 before the first element with value 3 of list2
	// - find() returns an iterator to the first element with value 3
	list2.splice(find(list2.begin(),list2.end(), // destination position
	3),
	list1); // source list
	printLists(list1, list2);
	// move first element of list2 to the end
	list2.splice(list2.end(), // destination position
	list2, // source list
	list2.begin()); // source position
	printLists(list1, list2);
	// sort second list, assign to list1 and remove duplicates
	list2.sort();
	list1 = list2;
	list2.unique();
	printLists(list1, list2);
	// merge both sorted lists into the first list
	list1.merge(list2);
	printLists(list1, list2);
}

void test_forward_list()
{
	forward_list<int> l1 = { 1, 2, 3, 4, 5 };
	forward_list<int> l2 = { 97, 98, 99 };
	// find 3 in l1
	auto pos1=l1.before_begin();
	for (auto pb1=l1.begin(); pb1 != l1.end(); ++pb1, ++pos1) {
		if (*pb1 == 3) {
		break; // found
		}
	}
	
	// find 99 in l2
	auto pos2=l2.before_begin();
	for (auto pb2=l2.begin(); pb2 != l2.end(); ++pb2, ++pos2) {
		if (*pb2 == 99) {
		break; // found
		}
	}
	// splice 3 from l1 to l2 before 99
	l1.splice_after(pos2, std::move(l2), // destination
	pos1); // source
	PRINT_ELEMENTS(l1,"l1: ");
	PRINT_ELEMENTS(l2,"l2: ");
}


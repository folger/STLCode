#include <set>
#include <algorithm>
#include <iterator>
#include "utils.h"
#include "STL_test.h"
using namespace std;

class RuntimeCmp {
public:
	enum cmp_mode {normal, reverse};
private:
	cmp_mode mode;
public:
	// constructor for sorting criterion
	// - default criterion uses value normal
	RuntimeCmp (cmp_mode m=normal) : mode(m) {
	}
	// comparison of elements
	// - member function for any element type
	template <typename T>
	bool operator() (const T& t1, const T& t2) const {
		return mode==normal ? t1<t2
		: t2<t1;
	}
	// comparison of sorting criteria
	bool operator== (const RuntimeCmp& rc) const {
		return mode == rc.mode;
	}
};

static void test_set_runtime_sorting_criterion()
{
	PS;

	typedef set<int, RuntimeCmp> IntSet;
	
	// create, fill, and print set with normal element order
	// - uses default sorting criterion
	IntSet coll1 = { 4, 7, 5, 1, 6, 2, 5 };
	PRINT_ELEMENTS (coll1, "coll1: ");
	// create sorting criterion with reverse element order
	RuntimeCmp reverse_order(RuntimeCmp::reverse);
	// create, fill, and print set with reverse element order
	IntSet coll2(reverse_order);
	coll2 = { 4, 7, 5, 1, 6, 2, 5 };
	PRINT_ELEMENTS (coll2, "coll2: ");
	// assign elements AND sorting criterion
	coll1 = coll2;
	coll1.insert(3);
	PRINT_ELEMENTS (coll1, "coll1: ");
	
	// just to make sure...
	if (coll1.value_comp() == coll2.value_comp()) {
		cout << "coll1 and coll2 have the same sorting criterion"
		<< endl;
	}
	else {
		cout << "coll1 and coll2 have a different sorting criterion"
		<< endl;
	}
	
	PS;
}

#define my_set multiset
void test_set()
{
	PS;
	// type of the collection:-
	// - no duplicates
	// - elements are integral values
	// - descending order
	my_set<int,greater<int>> coll1;
	// insert elements in random order using different member functions
	coll1.insert({4,3,5,1,6,2});
	coll1.insert(5);
	// print all elements
	for (int elem : coll1) {
		cout << elem << ' ';
	}
	cout << endl;
	// insert 4 again and process return value
	// auto status = coll1.insert(4);
	// if (status.second) {
	// cout << "4 inserted as element "
	// << distance(coll1.begin(),status.first) + 1 << endl;
	// }
	// else {
	// cout << "4 already exists" << endl;
	// }
	auto iPos = coll1.insert(4);
	cout << "4 inserted as element "
	<< distance(coll1.begin(),iPos) + 1 << endl;
	// assign elements to another set with ascending order
	my_set<int> coll2(coll1.cbegin(),coll1.cend());
	// print all elements of the copy using stream iterators
	copy (coll2.cbegin(), coll2.cend(),
	ostream_iterator<int>(cout," "));
	cout << endl;
	// remove all elements up to element with value 3
	coll2.erase (coll2.begin(), coll2.find(3));
	// remove all elements with value 5
	int num;
	num = coll2.erase (5);
	cout << num << " element(s) removed" << endl;
	// print all elements
	copy (coll2.cbegin(), coll2.cend(),
	ostream_iterator<int>(cout," "));
	cout << endl;
	PS;
	
	test_set_runtime_sorting_criterion();
}
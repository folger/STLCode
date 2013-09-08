#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <iterator>
#include <string>
using namespace std;
#include "utils.h"
#include "STL_test.h"

// from boost (functional/hash):
// see http://www.boost.org/doc/libs/1_35_0/doc/html/hash/combine.html
template <typename T>
inline void hash_combine (size_t& seed, const T& val)
{
	seed ^= hash<T>()(val) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

template <typename T>
inline void hash_val (size_t& seed, const T& val)
{
	hash_combine(seed,val);
}

template <typename T, typename... Types>
inline void hash_val (size_t& seed, const T& val, const Types&... types)
{
	hash_combine(seed, val);
	hash_val(seed, types...);
}

class Customer
{
private:
	string fname;
	string lname;
	long no;

public:
	Customer(const string& fn, const string& ln, long n) : fname(fn), lname(ln), no(n)
	{
	}
	
	const string& firstname() const { return fname; }
	const string& lastname() const { return lname; }
	long number() const { return no; }

	friend ostream& operator << (ostream& strm, const Customer& c)
	{
		return strm << "[" << c.fname << "," << c.lname << "," << c.no << "]";
	}

	friend class CustomerHash;
	friend class CustomerEqual;
};

class CustomerHash
{
public:
	size_t operator()(const Customer& customer) const
	{
		size_t seed = 0;
		hash_val(seed, customer.fname, customer.lname, customer.no);
		return seed;
	}
};

class CustomerEqual
{
public:
	bool operator() (const Customer& c1, const Customer& c2) const {
		return c1.no == c2.no;
	}
};

static void test_unorder_container_multi()
{
	PSH("test_unorder_container_multi");
	
	// create and initialize, expand, and print unordered multiset
	unordered_multiset<int> coll = { 1,2,3,5,7,11,13,17,19,77 };
	coll.insert({-7,17,33,-11,17,19,1,13});
	PRINT_ELEMENTS(coll);
	// remove all elements with specific value
	coll.erase(17);
	// remove one of the elements with specific value
	auto pos = coll.find(13);
	if (pos != coll.end()) {
		coll.erase(pos);
	}
	PRINT_ELEMENTS(coll);
	
	PS;
}

static void test_unorder_container_simple()
{
	PSH("test_unorder_container_simple");
	
	// create and initialize unordered set
	unordered_set<int> coll = { 1,2,3,5,7,11,13,17,19,77 };
	// print elements
	// - elements are in arbitrary order

	PRINT_ELEMENTS(coll);
	// insert some additional elements
	// - might cause rehashing and create different order
	coll.insert({-7,17,33,-11,17,19,1,13});
	PRINT_ELEMENTS(coll);
	// remove element with specific value
	coll.erase(33);
	// insert sum of all existing values
	coll.insert(accumulate(coll.begin(),coll.end(),0));
	PRINT_ELEMENTS(coll);
	// check if value 19 is in the set
	if (coll.find(19) != coll.end()) {
		cout << "19 is available" << endl;
	}
	// remove all negative values
	unordered_set<int>::iterator pos;
	for (pos=coll.begin(); pos!= coll.end(); ) {
		if (*pos < 0) {
			pos = coll.erase(pos);
		}
		else {
			++pos;
		}
	}
	PRINT_ELEMENTS(coll);
	PS;
}

static void test_unorder_container_own_hash_function()
{
	PSH("test_unorder_container_own_hash_function");
	// unordered set with own hash function and equivalence criterion
	unordered_set<Customer,CustomerHash,CustomerEqual> custset;
	custset.insert(Customer("nico","josuttis",42));
	PRINT_ELEMENTS(custset);
	PS;
}

static void test_unorder_container_using_labmda_as_hash_function()
{
	PSH("test_unorder_container_using_labmda_as_hash_function");
	// lambda for user-defined hash function
	auto hash = [] (const Customer& c) {
		size_t seed = 0;
		hash_val(seed, c.firstname(),c.lastname(),c.number());
		return seed;
	};
	// lambda for user-defined equality criterion
	auto eq = [] (const Customer& c1, Customer& c2) {
		return c1.number() == c2.number();
	};
	// unordered set with own hash function and equivalence criterion
	unordered_set<Customer,decltype(hash), decltype(eq)> custset(10, hash, eq);
	custset.insert(Customer("nico","josuttis",42));
	PRINT_ELEMENTS(custset);
	PS;
}

void test_unorder_container()
{
	test_unorder_container_simple();
	test_unorder_container_multi();
	test_unorder_container_own_hash_function();
	test_unorder_container_using_labmda_as_hash_function();
}



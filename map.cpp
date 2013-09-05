#include <map>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include "utils.h"
#include "map.h"
using namespace std;

static void test_map_simple()
{
	PS;
	
	map<string,double> coll { { "tim", 9.9 },
	{ "struppi", 11.77 }
	} ;
	// square the value of each element:
	for_each (coll.begin(), coll.end(),
	[] (pair<const string,double>& elem) {
	elem.second *= elem.second;
	});
	
	// print each element:
	for_each (coll.begin(), coll.end(),
	[] (const map<string,double>::value_type& elem) {
	cout << elem.first << ": " << elem.second << endl;
	});
	
	PS;
}

static void test_map_as_associative_array()
{
	PS;
	
	// create map / associative array
	// - keys are strings
	// - values are floats
	typedef map<string,float> StringFloatMap;
	StringFloatMap stocks; // create empty container
	// insert some elements
	stocks["BASF"] = 369.50;
	stocks["VW"] = 413.50;
	stocks["Daimler"] = 819.00;
	stocks["BMW"] = 834.00;
	stocks["Siemens"] = 842.20;
	
	// print all elements
	StringFloatMap::iterator pos;
	cout << left; // left-adjust values
	for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
	cout << "stock: " << setw(12) << pos->first
	<< "price: " << pos->second << endl;
	}
	cout << endl;
	// boom (all prices doubled)
	for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
	pos->second *= 2;
	}
	// print all elements
	for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
	cout << "stock: " << setw(12) << pos->first
	<< "price: " << pos->second << endl;
	}
	cout << endl;
	// rename key from "VW" to "Volkswagen"
	// - provided only by exchanging element
	stocks["Volkswagen"] = stocks["VW"];
	stocks.erase("VW");
	// print all elements
	for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
	cout << "stock: " << setw(12) << pos->first
	<< "price: " << pos->second << endl;
}
	
	PS;
}

static void test_map_as_associative_dictionary()
{
	PS;
	
	// create multimap as string/string dictionary
	multimap<string,string> dict;
	// insert some elements in random order
	dict.insert ( { {"day","Tag"}, {"strange","fremd"},
	{"car","Auto"}, {"smart","elegant"},
	{"trait","Merkmal"}, {"strange","seltsam"},
	{"smart","raffiniert"}, {"smart","klug"},
	{"clever","raffiniert"} } );
	// print all elements
	cout.setf (ios::left, ios::adjustfield);
	cout << ' ' << setw(10) << "english "
	<< "german " << endl;
	cout << setfill('-') << setw(20) << ""
	<< setfill(' ') << endl;
	for ( const auto& elem : dict ) {
	cout << ' ' << setw(10) << elem.first
	<< elem.second << endl;
	}
	cout << endl;
	
	// print all values for key "smart"
	string word("smart");
	cout << word << ": " << endl;
	for (auto pos = dict.lower_bound(word);
	pos != dict.upper_bound(word);
	++pos) {
	cout << " " << pos->second << endl;
	}
	// print all keys for value "raffiniert"
	word = ("raffiniert");
	cout << word << ": " << endl;
	for (const auto& elem : dict) {
	if (elem.second == word) {
	cout << " " << elem.first << endl;
	}
	}
	
	PS;
}

void test_map()
{
	test_map_simple();
	test_map_as_associative_array();
	test_map_as_associative_dictionary();
}
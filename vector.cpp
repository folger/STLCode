#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <iterator>
#include "utils.h"
#include "vector.h"
using namespace std;

void test_vector()
{
	PS;

	std::vector<std::string> sentence;
	
	sentence.reserve(5);
	
	sentence.push_back("Hello");
	sentence.insert(sentence.end(), {"how", "are", "you", "?"});
	
	std::copy(sentence.cbegin(), sentence.cend(),
		std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;
	
	std::cout << " max_size(): " << sentence.max_size() << std::endl;
	std::cout << " size(): " << sentence.size() << std::endl;
	std::cout << " capacity(): " << sentence.capacity() << std::endl;
	
	// swap second and fourth element
	swap (sentence[1], sentence[3]);
	// insert element "always" before element "?"
	sentence.insert (find(sentence.begin(),sentence.end(),"?"),
	"always");
	// assign "!" to the last element
	sentence.back() = "!";
	// print elements separated with spaces
	copy (sentence.cbegin(), sentence.cend(),
	ostream_iterator<string>(cout," "));
	cout << endl;
	// print some ‘‘technical data’’ again
	cout << " size(): " << sentence.size() << endl;
	cout << " capacity(): " << sentence.capacity() << endl;
	// delete last two elements
	sentence.pop_back();
	sentence.pop_back();
	// shrink capacity (since C++11)
	sentence.shrink_to_fit();
	// print some ‘‘technical data’’ again
	cout << " size(): " << sentence.size() << endl;
	cout << " capacity(): " << sentence.capacity() << endl;
	
	PS;
}

void test_deque()
{
	PS;
	
	// create empty deque of strings
	deque<string> coll;
	// insert several elements
	coll.assign (3, string("string"));
	coll.push_back ("last string");
	coll.push_front ("first string");
	// print elements separated by newlines
	copy (coll.cbegin(), coll.cend(),
	ostream_iterator<string>(cout,"\n"));
	cout << endl;
	// remove first and last element
	coll.pop_front();
	coll.pop_back();
	
	// insert ‘‘another’’ into every element but the first
	for (unsigned i=1; i<coll.size(); ++i) {
	coll[i] = "another " + coll[i];
	}
	// change size to four elements
	coll.resize (4, "resized string");
	// print elements separated by newlines
	copy (coll.cbegin(), coll.cend(),
	ostream_iterator<string>(cout,"\n"));
	
	PS;
}
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;
using namespace std::placeholders;
#include "utils.h"
#include "STL_test.h"

static void test_binder()
{
	PSH("test_binder");
	
	auto plus10 = std::bind(std::plus<int>(),
	std::placeholders::_1,
	10);
	std::cout << "+10: " << plus10(7) << std::endl;
	auto plus10times2 = std::bind(std::multiplies<int>(),
	std::bind(std::plus<int>(),
	std::placeholders::_1,
	10),
	2);
	std::cout << "+10 *2: " << plus10times2(7) << std::endl;
	auto pow3 = std::bind(std::multiplies<int>(),
	std::bind(std::multiplies<int>(),
	std::placeholders::_1,
	std::placeholders::_1),
	std::placeholders::_1);
	std::cout << "x*x*x: " << pow3(7) << std::endl;
	auto inversDivide = std::bind(std::divides<double>(),
	std::placeholders::_2,
	std::placeholders::_1);
	std::cout << "invdiv: " << inversDivide(49,7) << std::endl;
	
	PS;
}

void test_functor()
{
	test_binder();
}
#include <utility>
#include <iostream>
#include <tuple>
#include <functional>
#include "Pairs.h"
#include "utils.h"

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1,T2>& p)
{
	return os << "(" << p.first << "," << p.second << ")";
}

class Foo
{
public:
	Foo(std::tuple<int,float> t)
	{
		std::cout << "Foo::Foo(tuple)" << std::endl;
	}
	template <typename... Args>
	Foo(Args... args)
	{
		std::cout << "Foo::Foo(args...)" << std::endl;
	}
};

void test_pair()
{	
	typedef std::pair<int, float> IntFloatPair;
	auto p = std::make_pair(10, 20);
	
	std::cout << p << std::endl;
	PS;
	
	std::cout << std::get<0>(p) << std::endl;
	std::cout << std::get<1>(p) << std::endl;
	PS;
	
	std::cout << std::tuple_size<IntFloatPair>::value << std::endl;
	PS;
	
	std::tuple_element<0, IntFloatPair>::type p0 = std::get<0>(p);
	std::cout << p0 << std::endl;


	std::tuple<int,float> t(1,2.22);
	
	std::pair<int,Foo> p1 (42, t);
	std::pair<int,Foo> p2 (std::piecewise_construct, std::make_tuple(42), t);
	PS;
	
	int i = 0;
	auto pp = std::make_pair(std::ref(i), std::ref(i));
	++pp.first;
	++pp.second;
	std::cout << "i: " << i << std::endl;
	
	std::tie(std::ignore, i) = std::make_pair(100, 200);
	std::cout << "i: " << i << std::endl;
	
	PS;
}
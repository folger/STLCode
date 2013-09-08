#include <iostream>
#include <tuple>
#include <string>
#include <complex>
#include "STL_test.h"
#include "utils.h"

template <int IDX, int MAX, typename... ARGS>
struct PRINT_TUPLE
{
	static void print(std::ostream& os, const std::tuple<ARGS...>& t)
	{
		os << std::get<IDX>(t) << (IDX+1 == MAX ? "" : ",");
		PRINT_TUPLE<IDX+1, MAX, ARGS...>::print(os, t);
	}
};

template <int MAX, typename... ARGS>
struct PRINT_TUPLE<MAX, MAX, ARGS...>
{
	static void print(std::ostream& os, const std::tuple<ARGS...>& t)
	{
	}
};

template <typename... ARGS>
std::ostream& operator<<(std::ostream& os, const std::tuple<ARGS...>& t)
{
	os << "[";
	PRINT_TUPLE<0, sizeof...(ARGS), ARGS...>::print(os, t);
	return os << "]";
}

static void print_tuple()
{
	std::tuple<std::string, int, int, std::complex<double>> t;
	std::cout << t << std::endl;
	PS;

	std::tuple<int,float,std::string> t1(41, 6.3, "nico");
	std::cout << std::get<0>(t1) << std::endl;
	std::cout << std::get<1>(t1) << std::endl;
	std::cout << std::get<2>(t1) << std::endl;
	PS;

	auto t2 = std::make_tuple(22, 44, "nico");
	std::cout << t2 << std::endl;
	PS;
}

static void extract_values()
{
	std::tuple <int,float,std::string> t(77,1.1,"more light");
	int i;
	float f;
	std::string s;
	
	std::tie(i,f,s) = t;
	
	std::cout << "i: " << i << std::endl;
	std::cout << "f: " << f << std::endl;
	std::cout << "s: " << s << std::endl;
}

void test_tuple()
{
	print_tuple();
	extract_values();
}
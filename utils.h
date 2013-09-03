#pragma once

#include <iostream>

#define PS print_separator()
void print_separator();

template <typename T>
void PRINT_ELEMENTS(const T& coll, const char* optstr = "", const char* sepstr = " ")
{
	std::cout << optstr;
	for ( const auto& elem : coll )
	{
		std::cout << elem << sepstr;
	}
	std::cout << std::endl;
}
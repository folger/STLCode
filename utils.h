#pragma once

#include <iostream>

#define PS print_separator()
#define PSH(_lpcszHint) print_separator(_lpcszHint)
void print_separator(const char* lpcszHint = "");

template <typename T>
inline void PRINT_ELEMENTS(const T& coll, const char* optstr = "", const char* sepstr = " ")
{
	std::cout << optstr;
	for ( const auto& elem : coll )
	{
		std::cout << elem << sepstr;
	}
	std::cout << std::endl;
}

template <typename T>
inline void INSERT_ELEMENTS (T& coll, int first, int last)
{
	for (int i=first; i<=last; ++i) {
		coll.insert(coll.end(),i);
	}
}


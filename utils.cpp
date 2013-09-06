#include <iostream>
#include <iomanip>

void print_separator(const char* lpcszHint/* = ""*/)
{
	std::cout << std::left << std::setfill('-') << std::setw(70) << lpcszHint << std::setfill(' ') << std::endl;
}
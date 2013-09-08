#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "utils.h"
#include "STL_test.h"

void test_shared_ptr()
{
	PS;
	std::shared_ptr<std::string> pNico(new std::string("nico"),
								[](std::string* p)
								{
									std::cout << "delete " << *p << std::endl;
									delete p;
								}
								);
    std::shared_ptr<std::string> pJutta(new std::string("jutta"),
    							[](std::string* p)
								{
									std::cout << "delete " << *p << std::endl;
									delete p;
								}
    							);

	(*pNico)[0] = 'N';
	pJutta->replace(0,1,"J");

	std::vector<std::shared_ptr<std::string>> whoMadeCoffee;
	whoMadeCoffee.push_back(pJutta);
	whoMadeCoffee.push_back(pJutta);
	whoMadeCoffee.push_back(pNico);
	whoMadeCoffee.push_back(pJutta);
	whoMadeCoffee.push_back(pNico);

	for ( auto ptr : whoMadeCoffee )
	{
		std::cout << *ptr << std::endl;
	}
	PS;

	*pNico = "Folger";
	for ( auto ptr : whoMadeCoffee )
	{
		std::cout << *ptr << std::endl;
	}
	PS;

	std::cout << "use_count: " << whoMadeCoffee[0].use_count() << std::endl;
}
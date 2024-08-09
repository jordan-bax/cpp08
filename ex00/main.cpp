#include <iostream>
#include <list>
#include <map>
#include <vector>
#include "easyfind.hpp"

int	random_number()
{
	return (std::rand() % 300);
}
int	main(void)
{
	std::list<int> lst(5);
	std::vector<int> vector_list(3);
	std::srand(unsigned(time(NULL)));
	std::vector<int> generate(150);
	std::generate(generate.begin(), generate.end(), &random_number);

	vector_list.push_back(4);
	vector_list.push_back(5);
	vector_list.push_back(8);
	lst.push_back(5);
	lst.push_back(8);
	lst.push_back(2);
	lst.push_back(6);
	lst.push_back(3);
	try
	{
		std::cout << *easyfind(lst, 5) << std::endl;
		std::cout << *easyfind(vector_list, 5) << std::endl;
		std::cout << *easyfind(generate, 5) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::sort(generate.begin(), generate.end());
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "index["<< i << "];" << generate[i] << " ";
	}

	return 0;

}
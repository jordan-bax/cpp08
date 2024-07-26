#include <iostream>
#include <list>
#include <map>
#include <vector>
#include "easyfind.hpp"

int	random_number()
{
	return (std::rand() % 100);
}
int	main(void)
{
	std::list<int> lst(5);
	std::vector<int> vector_list(3);
	std::srand(unsigned(time(NULL)));
	std::vector<int> v(100);
	std::generate(v.begin(), v.end(), &random_number);
	//std::ranges::generate_random(lst.begin())

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
		std::cout << *std::adjacent_find(lst.begin(), lst.end()) << std::endl;
		std::cout << *easyfind(v, 5) << std::endl;
		/* code */
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 0;

}
#include <iostream>
#include "MutantStack.hpp"
#include <vector>

int main()
{
	// making and filling stacks
	std::stack<int> test_stack;
	MutantStack<int> mstack;
	test_stack.push(5);
	mstack.push(5);
	mstack.push(17);
	std::cout << test_stack.top() << std::endl;
	std::cout << mstack.top() << " " <<mstack[1] << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	// making en testing the iterators
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	MutantStack<int> mstack2(mstack);
	mstack.pop();
	it = mstack2.begin();
	ite = mstack2.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	// testing assignments of old stack
	std::stack<int> s(mstack);
	std::cout << std::endl;
	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}
	return 0;
}
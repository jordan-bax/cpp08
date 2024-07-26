#pragma once
#include <algorithm>

template <typename T>
typename T::const_iterator easyfind(T const & int_container, int const & i){
	typename T::const_iterator	it;

	it = std::find(int_container.begin(), int_container.end(), i);
	if (it == int_container.end())
		throw std::bad_exception();
	return (it);
};

#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
private:
	std::vector<int> _numbers;
	Span();

public:
	Span( unsigned int Number );
	Span( Span const & src );
	Span( std::vector<int> const & src );
	~Span();

	Span & operator=( Span const & rhs );
	Span & operator=( std::vector<int> const & rhs );
	void	addNumber(int Number);
	int 	shortestSpan() const;
	int 	longestSpan() const;
	void	generate_on_all(int (*f)());
	void	display_content()const;
};

std::ostream & operator<<( std::ostream & o, Span const & rhs);

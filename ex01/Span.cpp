#include "Span.hpp"
#include "limits"

Span::Span() {
	std::cout << "span is created"<< std::endl;
}
Span::Span( unsigned int Number ) {
	this->_numbers.reserve(Number);
	std::cout << "span is created"<< std::endl;
}
Span::Span( Span const & src ) {
	// this->_numbers = new std::vector<int>[src._numbers->max_size()];
	this->_numbers = src._numbers;// needs work
	std::cout << "span is created"<< std::endl;
}
Span::~Span() {
	std::cout << "span is deleted"<< std::endl;
}

Span & Span::operator=( Span const & rhs ) {
	// this->_numbers = new std::vector<int>[rhs._numbers->max_size()];
	this->_numbers = rhs._numbers;// needs work
	return *this;
}
void	Span::addNumber(int Number){
	if (this->_numbers.size() >= this->_numbers.capacity())
		throw std::bad_exception();
	this->_numbers.push_back(Number);
}
int		Span::shortestSpan() const{
	std::vector<int> temp;
	int	diff = std::numeric_limits<int>::max();
	if (this->_numbers.size() < 2)
		throw std::bad_exception();
	temp = this->_numbers;
	std::sort(temp.begin(),temp.end());
	for(std::vector<int>::const_iterator it = temp.begin();it + 1 != temp.end();it++)
	{
		if (*(it + 1) - *it < diff)
			diff = *(it + 1) - *it;
	}
	return diff;
}
int 	Span::longestSpan() const{
	int		long_span;
	if (this->_numbers.size() < 2)
		throw std::bad_exception();
	long_span = *std::max_element(this->_numbers.begin(), this->_numbers.end());
	long_span -= *std::min_element(this->_numbers.begin(), this->_numbers.end());
	return long_span;
}
void	Span::generate_on_all(int (*f)()){
	this->_numbers.resize(this->_numbers.capacity());
	std::generate(this->_numbers.begin(), this->_numbers.end(), f);
}
void	Span::display_content()const{
	for(std::vector<int>::const_iterator it = this->_numbers.begin();it != this->_numbers.end();it++)
		std::cout << *it << ", ";
	std::cout << std::endl;
}

std::ostream & operator<<( std::ostream & o, Span const & rhs) {
	o << rhs.shortestSpan() << ", " << rhs.longestSpan() << ", ";
	return o;
}

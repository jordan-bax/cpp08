#pragma once
#include <iostream>
#include <stack>

template<typename T>
class MutantStack
{
private:
	std::stack<T> _stack;
	unsigned int 	_size;
	// T*				

public:
	MutantStack(){};
	// MutantStack(  );
	MutantStack( MutantStack const & src ){_stack = src._stack;};
	~MutantStack(){};

	 class iterator : public std::iterator<
                                std::input_iterator_tag, // iterator_category
                                T,                    // value_type
                                T,                    // difference_type
                                const T*,             // pointer
                                T                     // reference
                            > {
        T num = FROM;
    public:
        explicit iterator(T _num = 0) : num(_num) {}
        iterator& operator++() { num = TO >= FROM ? num + 1: num - 1; return *this; }
        iterator operator++(int) { iterator retval = *this; ++(*this); return retval; }
        bool operator==(iterator other) const { return num == other.num; }
        bool operator!=(iterator other) const { return !(*this == other); }
        reference operator*() const { return num; }
    };
    iterator begin() { return iterator(FROM); }
    iterator end() { return iterator(TO >= FROM? TO + 1 : TO - 1); }

	// MutantStack &	operator=( MutantStack const & rhs );
	bool			empty()const{ return _stack.empty();};
	unsigned int	size()const{ return _stack.size();};
	T &				top(){return _stack.top();};
	void			push(T content){_stack.push(content);};
	void			pop(){_stack.pop();};
	void			emplace(T content){_stack.emplace(content);};
	void			swap(MutantStack<T> & rhs){_stack.swap(rhs);};
	// static T*		iterator(){return };


};

// std::ostream & operator<<( std::ostream & o, MutantStack const & rhs){};

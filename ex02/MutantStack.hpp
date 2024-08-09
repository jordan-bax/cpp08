#pragma once
#include <iostream>
#include <stack>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T>
{
private:
	T*				_begin; // a pointer to the first element

public:
	MutantStack():_begin(0){};
	MutantStack( MutantStack const & src ){*this = src;};
	~MutantStack(){};

	 class iterator : public std::iterator<
                                std::input_iterator_tag, // iterator_category
                                T*                    // value_type
                            > {
        T* _pointer;
    public:
        explicit iterator(T* pointer = 0) : _pointer(pointer) {}
        iterator& operator--() { _pointer = _pointer - 1; return *this; }
        iterator operator--(int) { iterator retvalue = *this; --(*this); return retvalue; }
        iterator& operator++() { _pointer = _pointer + 1; return *this; }
        iterator operator++(int) { iterator retvalue = *this; ++(*this); return retvalue; }
        bool operator==(iterator other) const { return _pointer == other._pointer; }
        bool operator!=(iterator other) const { return !(*this == other); }
        T& operator*() const { return *_pointer; }
    };
    iterator begin() { return iterator(_begin); }
    iterator end() { return iterator(_begin + std::stack<T>::size()); }
    iterator const cbegin()const { return iterator(_begin); }
    iterator const cend()const { return iterator(_begin + std::stack<T>::size()); }

	MutantStack &	operator=( MutantStack const & rhs ){// need to manualy deep copy for accurate begin pointer
		while (!std::stack<T>::empty()) // emptying the stack
			std::stack<T>::pop();
		MutantStack<int>::iterator it = rhs.cbegin();
		MutantStack<int>::iterator ite = rhs.cend();
		while (it != ite) // iterate for deep copy
		{
			this->push(*it);
			it++;
		}
		return *this;
	};
	T &		operator[](unsigned int index) const { // extra Array subscript operator
		if (index >= 0 && index < std::stack<T>::size()) 
			return *(_begin + index);
		else
			throw std::bad_exception(); 
	};
	void			push(T content){std::stack<T>::push(content); if (std::stack<T>::size() == 1) _begin = &std::stack<T>::top();};
	void			push_back(T content){std::stack<T>::push(content); if (std::stack<T>::size() == 1) _begin = &std::stack<T>::top();};
};
// old draft  is not correct

// class MutantStack
// {
// private:
// 	std::stack<T> _stack;
// 	T*				_begin;

// public:
// 	MutantStack():_begin(0){};
// 	// MutantStack(  );
// 	MutantStack( MutantStack const & src ){_stack = src._stack;};
// 	~MutantStack(){};

// 	 class iterator : public std::iterator<
//                                 std::input_iterator_tag, // iterator_category
//                                 T*                    // value_type
//                             > {
//         T* _pointer;
//     public:
//         explicit iterator(T* pointer = 0) : _pointer(pointer) {}
//         iterator& operator--() { _pointer = _pointer - 1; return *this; }
//         iterator operator--(int) { iterator retvalue = *this; --(*this); return retvalue; }
//         iterator& operator++() { _pointer = _pointer + 1; return *this; }
//         iterator operator++(int) { iterator retvalue = *this; ++(*this); return retvalue; }
//         bool operator==(iterator other) const { return _pointer == other._pointer; }
//         bool operator!=(iterator other) const { return !(*this == other); }
//         T& operator*() const { return *_pointer; }
//     };
//     iterator begin() { return iterator(_begin); }
//     iterator end() { return iterator(_begin + _stack.size()); }

// 	MutantStack &	operator=( MutantStack const & rhs ){_stack};
// 	T &		operator[](unsigned int index) const {
// 		if (index >= 0 && index < _stack.size()) 
// 			return *(_begin + index);
// 		else
// 			throw std::bad_exception(); 
// 	};
// 	bool			empty()const{ return _stack.empty();};
// 	unsigned int	size()const{ return _stack.size();};
// 	T &				top(){return _stack.top();};
// 	void			push(T content){_stack.push(content); if (_stack.size() == 1) _begin = &_stack.top();};
// 	void			push_back(T content){_stack.push(content); if (_stack.size() == 1) _begin = &_stack.top();};
// 	void			pop(){_stack.pop();};
// 	void			pop_back(){_stack.pop();};
// 	void			emplace(T content){_stack.emplace(content);};
// 	void			swap(MutantStack<T> & rhs){_stack.swap(rhs);};
// };

#ifndef STACK_H
#define STACK_H
#include <cstddef>
#include <vector>
#include <string>
#include <deque>
#include <iostream>

template <typename T>
//Stack(const char*) -> Stack<std::String>
class Stack {
private:
	std::vector<T> vec;
public:
	Stack() = default;
	Stack(Stack const&);
	void push(T const& value);
	void pop() ;
	T const& top() const;
	size_t size() const;	
	Stack& operator=(Stack const&);
	void print() const;
	friend std::istream& operator>> (std::istream& is, const Stack<T>& v);
};

template<> //spec for string
class Stack<std::string> {
private:
	std::deque<std::string> elems;
public:
	void push(std::string const&);
	void pop();
	std::string const& top() const;
};
#include "stack.tpp"
#endif //STACK_H
/*
void Stack<std::string>::push(std::stringconst& value) {
	elems.push_back(value);
}
void Stack<std::String>::pop() {
	elems.pop_back();
}
std::string const& Stack<std::string>::top() const {
	return elems.back();
}*/


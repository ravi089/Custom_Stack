// Stack class with some added functionality.
// Composition is preferred over Inheritance.

#ifndef STACK_H
#define STACK_H

#include <stack>
#include <string>

template <typename T>
class Stack
{
private:
	std::stack<T> _stack;
	int _stackSize;

	bool isStackEmpty() { return (_stackSize == 0); }
	// Helper routines for reversing the stack.
	void reverse__(std::stack<T>& _stack);
	void insert_reverse_(std::stack<T>& _stack, T element);
	// Helper routine for sorting the stack.
	void sort__(std::stack<T>& _stack);
	void insert_sort_(std::stack<T>& _stack, T element);
public:
	Stack() : _stackSize(0) {}
	// number of elements in stack.
	int getSizeOfStack() const { return _stackSize; }
	// add the element to stack.
	void addToStack(T data);
	// remove element from stack.
	void removeFromStack();
	// reverse the stack.
	void reverseStack() { reverse__(this->_stack); }
	// sort the stack.
	void sortStack() { sort__(this->_stack); }
	// print the stack.
	std::ostream& printStack(std::ostream& stream) const;
};

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Stack<T>& stack__)
{
	return stack__.printStack(stream);
}

template <typename T>
void Stack<T>::addToStack(T data)
{
	_stack.push(data);
	_stackSize++;
}

template <typename T>
void Stack<T>::removeFromStack()
{
	if (isStackEmpty()) return;

	_stack.pop();
	_stackSize--;
}

template <typename T>
void Stack<T>::insert_reverse_(std::stack<T>& _stack, T element)
{
	if (_stack.empty())
	{
		_stack.push(element);
		return;
	}

	T temp = _stack.top();
	_stack.pop();

	insert_reverse_(_stack, element);

	_stack.push(temp);
}

template <typename T>
void Stack<T>::reverse__(std::stack<T>& _stack)
{
	if (_stack.empty()) return;

	T element = _stack.top();
	_stack.pop();

	reverse__(_stack);

	insert_reverse_(_stack, element);
}

template <typename T>
void Stack<T>::insert_sort_(std::stack<T>& _stack, T element)
{
	if (_stack.empty())
	{
		_stack.push(element);
		return;
	}

	T temp = _stack.top();
	if (temp > element)
	{
		_stack.pop();
		insert_sort_(_stack, element);
		_stack.push(temp);
	}
	else
		_stack.push(element);
}

template <typename T>
void Stack<T>::sort__(std::stack<T>& _stack)
{
	if (_stack.empty()) return;

	T element = _stack.top();
	_stack.pop();

	sort__(_stack);

	insert_sort_(_stack, element);
}

template <typename T>
std::ostream& Stack<T>::printStack(std::ostream& stream) const
{
	stack<T> temp = this->_stack;
	while (!temp.empty())
	{
		stream << temp.top() << " ";
		temp.pop();
	}
	return stream;
}

#endif
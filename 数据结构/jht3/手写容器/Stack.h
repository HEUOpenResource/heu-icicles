#pragma once
template<typename T> class Stack {
private:
	class StackNode {
	public:
		StackNode* last;
		T data;
		template<typename T2>StackNode(T2 &&data);
	};
	int total;
	StackNode* head;
public:
	Stack();
	~Stack();
	Stack(const Stack<T>& data);
	Stack(Stack<T>&& data) noexcept;
	Stack<T>& operator= (Stack<T>&& data) noexcept;
	Stack<T>& operator= (const Stack<T>& data);
	void clear();
	bool isEmpty();
	int size();
	template<typename T2>void push(T2 &&data);
	T& front();
	void pop();
};

#include"Stack.cpp"
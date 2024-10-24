#ifndef __Stack_CPP__
#define __Stack_CPP__
#include"Stack.h"
#include<utility>

template<typename T>template<typename T2>Stack<T>::StackNode::StackNode(T2 &&data):data(std::forward<T2>(data)),last(nullptr){}

template<typename T>Stack<T>::Stack():head(nullptr),total(0){}
template<typename T>Stack<T>::~Stack() { clear(); }
template<typename T>Stack<T>::Stack(Stack<T>&& data) noexcept {
	head = data.head;
	total = data.total;
	data.head = nullptr;
	data.total = 0;
}
template<typename T>Stack<T>& Stack<T>::operator= (Stack<T>&& data) noexcept {
	head = data.head;
	total = data.total;
	data.head = nullptr;
	data.total = 0;
	return *this;
}
template<typename T> Stack<T>::Stack(const Stack<T>& data) {
	total = data.total;
	head = new StackNode(data.head->data);
	auto from = data.head->last;
	auto to = head;
	while (from) {
		to->last = new StackNode(from->data);
		to = to->last;
		from = from->last;
	}
}
template<typename T>Stack<T>& Stack<T>::operator=(const Stack<T>& data){
	total = data.total;
	head=new StackNode(data.head->data);
	auto from = data.head->last;
	auto to = head;
	while(from){
		to->last = new StackNode(from->data);
		to = to->last;
		from = from->last;
	}
	return *this;
}
template<typename T>bool Stack<T>::isEmpty() { return !total; }
template<typename T>int Stack<T>::size() { return total; }
template<typename T>void Stack<T>::clear() { while (!isEmpty()) { pop(); } delete head; }
template<typename T>template<typename T2>void Stack<T>::push(T2 &&data)
{
	if (head) {
		StackNode* temp = new StackNode(std::forward<T2>(data));
		temp->last = head;
		head = temp;
	}
	else {
		head = new StackNode(std::forward<T2>(data));
	}
	++total;
}
template<typename T>T& Stack<T>::front() { return head->data; }
template<typename T>
void Stack<T>::pop()
{
	StackNode* temp = head;
	head = head->last;
	delete temp;
	--total;
}

#endif // !__Stack_CPP__

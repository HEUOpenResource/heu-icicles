#include"LinkedList.h"
#include<utility>
#include<algorithm>
#ifndef __LinkedList_CPP__
#define __LinkedList_CPP__

template<typename T>template<typename T2> LinkedListNode<T>::LinkedListNode(T2&& data) : data(std::forward<T2>(data)), next(nullptr), last(nullptr) {}
template<typename T> LinkedListNode<T>::LinkedListNode(const LinkedListNode& d) : data(d.data), last(nullptr), next(nullptr) {}
template<typename T> LinkedListNode<T>& LinkedListNode<T>::operator=(const LinkedListNode& d) { data = d.data; last = nullptr; next = nullptr; return *this; }
template<typename T> LinkedListNode<T>* LinkedListNode<T>::getNext() { return next; }
template<typename T> LinkedListNode<T>* LinkedListNode<T>::getLast() { return last; }

template<typename T> LinkedList<T>::LinkedList() { end = head = nullptr; total = 0; }
template<typename T> LinkedList<T>::~LinkedList() { clear(); }
template<typename T> LinkedList<T>::LinkedList(LinkedList<T>&& data) noexcept :total(data.total), head(data.head),end(data.end) {
	data.total = 0;
	data.head = nullptr;
	data.end = nullptr;
}
template<typename T> LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&& data) noexcept {
	total = data.total;
	head = data.head;
	end = data.end;
	data.total = 0;
	data.head = nullptr;
	data.end = nullptr;
	return *this;
}
template<typename T> LinkedList<T>::LinkedList(const LinkedList<T>& data) {
	end = head = nullptr;
	total = 0;
	for (auto head = data.head; head; head = head->next) {
		add(head->data);
	}
}
template<typename T> LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& data)
{
	end = head = nullptr;
	total = 0;
	for (auto head = data.head; head; head = head->next) {
		add(head->data);
	}
	return *this;
}
template<typename T> bool LinkedList<T>::isEmpyt() { return !total; }
template<typename T> int LinkedList<T>::size() { return total; }
template<typename T> void LinkedList<T>::clear() { while (head) { remove(head); } }
template<typename T>
template<typename T2>
void LinkedList<T>::add(T2&& data)
{
	if (!head) {
		end = head = new LinkedListNode<T>(std::forward<T2>(data));
		if (!head)return;
		head->next = head->last = nullptr;
	}
	else {
		LinkedListNode<T>* temp = new LinkedListNode<T>(std::forward<T2>(data));
		if (!temp)return;
		temp->last = end;
		temp->next = nullptr;
		end->next = temp;
		end = temp;
	}
	++total;
}
template<typename T> LinkedListNode<T>* LinkedList<T>::getHead() { return head; }
template<typename T> LinkedListNode<T>* LinkedList<T>::getEnd() { return end; }
template<typename T> void LinkedList<T>::remove(LinkedListNode<T>* node) {
	if (node == head) {
		head = head->next;
	}
	if (node == end) {
		end = end->last;
	}
	if (node->last) {
		node->last->next = node->next;
	}
	if (node->next) {
		node->next->last = node->last;
	}
	--total;
	delete node;
}
template<typename T> void LinkedList<T>::sort(bool(*cmp)(const T& a, const T& b))
{
	for (auto i = head; i; i = i->next) {
		auto temp = i;
		for (auto j = i; j; j = j->next) {
			if (!cmp(temp->data, j->data))temp = j;
		}
		std::swap(i->data,temp->data);
	}
}
#endif // !__LinkedList_CPP__
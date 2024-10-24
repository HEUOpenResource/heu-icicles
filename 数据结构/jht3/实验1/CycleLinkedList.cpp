#include"CycleLinkedList.h"
#include<utility>
#ifndef __CycleLinkedList_CPP__
#define __CycleLinkedList_CPP__

template<typename T>template<typename T2> CycleLinkedListNode<T>::CycleLinkedListNode(T2 &&data) : data(std::forward<T2>(data)), next(nullptr), last(nullptr) {}
template<typename T> CycleLinkedListNode<T>* CycleLinkedListNode<T>::getNext() { return next; }
template<typename T> CycleLinkedListNode<T>* CycleLinkedListNode<T>::getLast() { return last; }
template<typename T> CycleLinkedListNode<T>::CycleLinkedListNode(const CycleLinkedListNode& d):data(d.data),last(nullptr),next(nullptr){}
template<typename T> CycleLinkedListNode<T>& CycleLinkedListNode<T>::operator=(const CycleLinkedListNode& d) { data = d.data; last = nullptr; next = nullptr; return *this; }

template<typename T> CycleLinkedList<T>::CycleLinkedList() { head = nullptr; total = 0; }
template<typename T> CycleLinkedList<T>::~CycleLinkedList() { clear(); }
template<typename T> CycleLinkedList<T>::CycleLinkedList(CycleLinkedList<T>&& data) noexcept:total(data.total),head(data.head) {
	data.total = 0;
	data.head = nullptr;
}
template<typename T> CycleLinkedList<T>& CycleLinkedList<T>::operator=(CycleLinkedList<T>&& data) noexcept {
	total = data.total;
	head = data.head;
	data.total = 0;
	data.head = nullptr;
	return *this;
}
template<typename T> CycleLinkedList<T>::CycleLinkedList(const CycleLinkedList<T>& data) {
	head=nullptr;
	total=0;
	if (data.total != 0) {
		add(data.head->data);
		for (auto head = data.head->next; head != data.head; head = head->next) {
			add(head->data);
		}
	}
}
template<typename T> CycleLinkedList<T>& CycleLinkedList<T>::operator=(const CycleLinkedList<T>& data)
{
	head=nullptr;
	total=0;
	if (data.total != 0) {
		add(data.head->data);
		for (auto head = data.head->next; head != data.head; head = head->next) {
			add(head->data);
		}
	}
	return *this;
}
template<typename T> bool CycleLinkedList<T>::isEmpyt() { return !total; }
template<typename T> int CycleLinkedList<T>::size() { return total; }
template<typename T> void CycleLinkedList<T>::clear() { while (head) { remove(head); } }
template<typename T>
template<typename T2>
void CycleLinkedList<T>::add(T2&& data)
{
	if (!head) {
		head = new CycleLinkedListNode<T>(std::forward<T2>(data));
		if (!head)return;
		head->next = head->last = head;
	}
	else {
		CycleLinkedListNode<T>* temp = new CycleLinkedListNode<T>(std::forward<T2>(data));
		if (!temp)return;
		temp->last = head->last;
		temp->next = head;
		head->last->next = temp;
		head->last = temp;
	}
	++total;
}
template<typename T> CycleLinkedListNode<T>* CycleLinkedList<T>::getHead() { return head; }
template<typename T> void CycleLinkedList<T>::remove(CycleLinkedListNode<T>* node) {
	if (node->next == node) {
		this->head = nullptr;
	}
	else {
		if (node == head)
			head = head->next;
		node->next->last = node->last;
		node->last->next = node->next;
	}
	--total;
	delete node;
}
#endif // !__CycleLinkedList_CPP__
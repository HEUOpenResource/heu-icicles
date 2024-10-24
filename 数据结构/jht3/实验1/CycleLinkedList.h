#pragma once
template<typename T> class CycleLinkedList;
template<typename T> class CycleLinkedListNode;

template<typename T> class CycleLinkedListNode {
private:
	friend class CycleLinkedList<T>;
	template<typename T2>CycleLinkedListNode(T2 &&d);
	CycleLinkedListNode<T>* last, * next;
	~CycleLinkedListNode() = default;
	CycleLinkedListNode(const CycleLinkedListNode& d);
	CycleLinkedListNode(CycleLinkedListNode&& d) = delete;
	CycleLinkedListNode& operator= (CycleLinkedListNode&& d) = delete;
	CycleLinkedListNode& operator= (const CycleLinkedListNode & d);
public:
	T data;
	CycleLinkedListNode<T>* getNext();
	CycleLinkedListNode<T>* getLast();
};

template<typename T> class CycleLinkedList {
private:
	CycleLinkedListNode<T>* head;
	int total;
public:
	CycleLinkedList();
	~CycleLinkedList();
	CycleLinkedList(const CycleLinkedList<T>& data);
	CycleLinkedList(CycleLinkedList<T>&& data) noexcept;
	CycleLinkedList<T>& operator= (CycleLinkedList<T>&& data) noexcept;
	CycleLinkedList<T>& operator= (const CycleLinkedList<T>& data);
	bool isEmpyt();
	int size();
	void clear();
	template<typename T2>void add(T2 &&data);
	CycleLinkedListNode<T>* getHead();
	void remove(CycleLinkedListNode<T>* node);
};
#include"CycleLinkedList.cpp"



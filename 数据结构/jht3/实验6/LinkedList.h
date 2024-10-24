#pragma once
#include<functional>
template<typename T> class LinkedList;
template<typename T> class LinkedListNode;

template<typename T> class LinkedListNode {
private:
	friend class LinkedList<T>;
	template<typename T2>LinkedListNode(T2&& data);
	~LinkedListNode() = default;
	LinkedListNode<T>* last, * next;
	LinkedListNode(const LinkedListNode& d);
	LinkedListNode(LinkedListNode&& d) = delete;
	LinkedListNode& operator= (LinkedListNode&& d) = delete;
	LinkedListNode& operator= (const LinkedListNode& d);
public:
	T data;
	inline LinkedListNode<T>* getNext() const;
	inline LinkedListNode<T>* getLast() const;
};

template<typename T> class LinkedList {
private:
	LinkedListNode<T>* head,*end;
	int total;
public:
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList<T>& data);
	LinkedList(LinkedList<T>&& data) noexcept;
	LinkedList<T>& operator= (LinkedList<T>&& data) noexcept;
	LinkedList<T>& operator= (const LinkedList<T>& data);
	inline bool isEmpty() const;
	inline int size() const;
	void clear();
	template<typename T2>void add(T2&& data);
	template<typename T2>inline void add(LinkedListNode<T>* node, T2&& data);
	template<typename T2>void addFirst(T2&& data);
	inline void addAll(const LinkedList<T> &list);
	void addAll(LinkedListNode<T>* node,const LinkedList<T> &list);
	T& get(const int id);
	const T& get(const int id) const;
	inline LinkedListNode<T>* getHead();
	inline LinkedListNode<T>* getEnd();
	inline const LinkedListNode<T>* getHead() const;
	inline const LinkedListNode<T>* getEnd() const;
	void remove(LinkedListNode<T>* node);
	void remove(const int id);
	void sort(const bool (*cmp)(const T &a,const T &b));
	void sort(const std::function<bool(const T &a,const T &b)> &cmp);
};
#include"LinkedList.cpp"
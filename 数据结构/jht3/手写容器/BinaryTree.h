#pragma once
#include<utility>
template<typename T> class BinaryTree {
public:
	BinaryTree<T> * lChild, * rChild;
	T data;
	BinaryTree():lChild(nullptr), rChild(nullptr){}
	template<typename T1>
	BinaryTree(T1 &&data):data(std::forward<T1>(data)),lChild(nullptr),rChild(nullptr){}
	~BinaryTree() {
		if(lChild)
			delete lChild;
		if(rChild)
			delete rChild;
	}
};
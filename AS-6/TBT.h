#ifndef TBT_H_
#define TBT_H_

#include <iostream>

template <class T>
class TBT;

template <class T>
class treeNode{
	T info;
	treeNode<T> *left,*right;
	int leftBit,rightBit;

	friend class TBT<T>;

public:
	treeNode(){
		info = 0;
		left=right=NULL;
		leftBit=rightBit=0;
	}
};


template <class T>
class TBT {
	treeNode<T> *root;
public:
	TBT();
	void search(T ele,treeNode<T> *&loc,treeNode<T> *&par);
	void insert(T ele);
	void inorderTraversal();
	void preorderTraversal();
};

#endif

/*
 * BST.h
 *
 *  Created on: Nov 9, 2020
 *      Author: jain
 */
#ifndef BST_H_
#define BST_H_

#include <iostream>

template <class T>
class BST;

template <class T>
class treeNode {

	T info;
	treeNode *rightNode;
	treeNode *leftNode;

	friend class BST<T>;

public:
	treeNode(){
		rightNode = NULL;
		leftNode = NULL;
	}
};


template <class T>
class BST {
	treeNode<T> *root,*loc,*par;

public:
	BST();
	void insert(T ele);
	void delete0();
	void delete1();
	void delete2(T ele);
	void search(T ele);
	int depth();
	void mirror();
	treeNode<T> * getRoot();
	void copy(BST<T> t);
	void parentWithChild();
	void leafNodes();
	void levelWiseTraversal();
};

#endif /* BST_H_ */

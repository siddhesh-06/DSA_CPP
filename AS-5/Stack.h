#ifndef STACKS_STACK_H_
#define STACKS_STACK_H_

#include <iostream>

template <class T>
class Stack;

template <class T>
class node{
	T info;
	node <T> *next;

	friend class Stack <T>;

public:
	node(){
		info = NULL;
		next = NULL;
	}
};

template <class T>
class Stack {
	node <T> *top;
public:
	Stack();
	void push(T ele);
	void pop();
	bool isEmpty();
	T isTop();
};

#endif


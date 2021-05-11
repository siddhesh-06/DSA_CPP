#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>

template <class T>
class Queue;

template <class T>
class queue_node {
	T info;
	queue_node *next;

	friend class Queue<T>;
public:
	queue_node(){
		info = NULL;
		next = NULL;
	}
};


template <class T>
class Queue {
	queue_node<T> *start;
public:
	Queue();
	void enqueue(T ele);
	void dequeue();
	bool isEmpty();
	T front();
};

#endif 

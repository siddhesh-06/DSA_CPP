#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_


template <class T>
class priorityQueue {

	int front,rear,n;
	T *arr;

public:
	priorityQueue(int num);
	void enqueue(T ele);
	void dequeue();
	T getFront();
	bool isEmpty();
};

#endif

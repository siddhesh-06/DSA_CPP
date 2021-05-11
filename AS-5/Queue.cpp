
#include "Queue.h"

#include <iostream>

using namespace std;

template <class T>
Queue<T>::Queue() {
	start = NULL;
}

template <class T>
void Queue<T>::enqueue(T ele){
	queue_node<T> *new1 = new queue_node<T>;
	new1->info = ele;
	new1->next = NULL;
	if(start == NULL){
		start = new1;
	}
	else{
		queue_node<T> *curr = start;

		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = new1;
	}
}

template <class T>
void Queue<T>::dequeue(){
	if(start == NULL){
		cout<<"The queue is already empty !!"<<endl;
	}
	else{
		queue_node<T> *temp = start->next;
		start->next = NULL;
		delete start;
		start = temp;
	}
}

template <class T>
bool Queue<T>::isEmpty(){
	if(start == NULL){
		return true;
	}
	return false;
}

template <class T>
T Queue<T>::front(){
	return start->info;
}


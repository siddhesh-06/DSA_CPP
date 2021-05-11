#include "priorityQueue.h"
#include <iostream>

using namespace std;

template <class T>
priorityQueue<T>::priorityQueue(int num) {
	n = num;
	front = -1;
	rear = -1;
	arr = new T [num];
}

template <class T>
void priorityQueue<T>::enqueue(T ele){
	if(rear==n-1){
		return;
	}

	else if(front==-1){
		front = 0;
		rear = 0;
		arr[rear] = ele;
	}
	else{
		rear++;
		int j = rear - 1;
		while(arr[j].getDist() > ele.getDist() && j>=front){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = ele;
	}
}

template <class T>
void priorityQueue<T>::dequeue(){

	if(front == -1){
		return;
	}
	else if(front==rear){
		front = -1;
		rear = -1;
	}
	else{
		front++;
	}
}

template <class T>
bool priorityQueue<T>::isEmpty(){
	if(front == -1){
		return true;
	}
	return false;
}

template <class T>
T priorityQueue<T>::getFront(){
	if(!isEmpty()){
		return arr[front];
	}
	return NULL;

}

#include "Stack.h"
#include <iostream>

using namespace std;

template <class T>
Stack<T>::Stack() {
	top = NULL;
}

template <class T>
void Stack<T>::push(T ele){
	node <T> *new1 = new node <T>;
	new1->info = ele;
	if(top == NULL){
		top = new1;
		top->next = NULL;
	}
	else{
		new1->next = top;
		top = new1;
	}
}

template <class T>
void Stack<T>::pop(){
	node <T> *temp = top->next;
	top->next = NULL;
	delete top;
	top = temp;
}

template <class T>
bool Stack<T>::isEmpty(){
	if(top == NULL){
		return true;
	}
	return false;
}

template <class T>
T Stack<T>::isTop(){
	return top->info;
}


#include "stack.h"
#include<iostream>
using namespace std;

template <class t>
Stack<t>::Stack(){
	top = NULL;
}

template <class t>
void Stack<t>::push(t info){
		node<t>* n = new node<t>;
		n->data = info;
		n->next = top;
		top = n;
}

template <class t>
void Stack<t>:: pop(){
		if (top == NULL){
			cout << "Underflow" << endl;
		}
		else{
			top = top->next;
		}
}

template <class t>
bool Stack<t>::isEmpty(){
		if (top == NULL){
			return true;
		}
		else{
			return false;
		}
}


template <class t>
t Stack<t>:: isTop(){
		return top->data;
}

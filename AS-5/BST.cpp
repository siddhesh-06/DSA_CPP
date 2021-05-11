#include "BST.h"
#include "Queue.h"
#include "Queue.cpp"
#include "Stack.h"
#include "Stack.cpp"
#include <iostream>

using namespace std;

template <class T>
BST<T>::BST() {
	root = NULL;
	par = NULL;
	loc = NULL;
}

template <class T>
void BST<T>::insert(T ele){
	treeNode<T> *new1 = new treeNode<T>;
	new1->info = ele;

	if(root == NULL){
		root = new1;
		root->rightNode = NULL;
		root->leftNode = NULL;
	}
	else{
		treeNode<T> *ptr = root;
		bool inserted = false;
		while(!inserted){
			if(ele > ptr->info){
				if(ptr->rightNode != NULL){
					ptr = ptr -> rightNode;
				}
				else{
					ptr->rightNode = new1;
					inserted = true;
				}
			}
			else if(ele < ptr->info){
				if(ptr->leftNode != NULL){
					ptr = ptr -> leftNode;
				}
				else{
					ptr->leftNode = new1;
					inserted = true;
				}
			}
			else{
				cout<<"The element is already in the tree !!";
				break;
			}
		}
	}
}

template <class T>
void BST<T>::search(T ele){

	treeNode<T> *ptr = root;
	loc = NULL;
	par = NULL;
	if(root == NULL){
		cout<<"The tree is empty !!"<<endl;
	}
	else{
		while(ptr != NULL){
			if(ptr->info == ele){
				loc = ptr;
				cout<<"Element Found"<<endl;
				break;
			}
			else if(ele > ptr->info){
				par = ptr;
				ptr = ptr -> rightNode;
				loc = ptr;
			}
			else{
				par = ptr;
				ptr = ptr->leftNode;
				loc = ptr;
			}
		}

		if(loc == NULL){
			cout<<"Element Not Found !!"<<endl;
		}
	}
}

template <class T>
void BST<T>::delete0(){

	if(loc != NULL){
		if(par == NULL){
			root = NULL;
		}
		else{
			if(loc == par->rightNode){
				par->rightNode = NULL;
			}
			else{
				par->leftNode = NULL;
			}
		}

		delete loc;
		loc = NULL;

	}
}

template <class T>
void BST<T>::delete1(){

	if(loc != NULL){
		if(loc->leftNode != NULL){
			if(par == NULL){
				root = loc->leftNode;
			}
			else{
				if(loc == par->leftNode){
					par->leftNode = loc->leftNode;
				}
				else{
					par->rightNode = loc->leftNode;
				}
				loc->leftNode = NULL;

			}
		}
		else{
			if(par == NULL){
				root = loc->leftNode;
			}
			else{
				if(loc == par->leftNode){
					par->leftNode = loc->rightNode;
				}
				else{
					par->rightNode = loc->rightNode;
				}
				loc->rightNode = NULL;

			}
		}
		delete loc;
		loc = NULL;
	}
}

template <class T>
void BST<T>::delete2(T ele){

	search(ele);
	if(loc != NULL){
		treeNode<T> *ptr1 = NULL;
		treeNode<T> *ptr2 = NULL;
		if(loc->leftNode == NULL && loc->rightNode == NULL){
			delete0();
		}
		else if(loc->rightNode != NULL && loc->leftNode != NULL){
			ptr2 = loc->rightNode;
			ptr1 = loc;
			while(ptr2->leftNode != NULL){
				ptr1 = ptr2;
				ptr2 = ptr2->leftNode;
			}
			loc->info = ptr2->info;
			if(ptr2->rightNode == NULL){
				loc = ptr2;
				par = ptr1;
				delete0();
				ptr2 = NULL;
				ptr1 = NULL;
				cout<<root->info<<endl;
			}
			else{
				loc = ptr2;
				par = ptr1;
				delete1();
				ptr2 = NULL;
				ptr1 = NULL;
			}
		}
		else{
			delete1();
		}
	}
}

template <class T>
void BST<T>::levelWiseTraversal(){
	Queue<treeNode<T>*> q;

	if(root != NULL){
		q.enqueue(root);

		while(!q.isEmpty()){
			treeNode<T> *node1 = q.front();
			q.dequeue();

			cout<<node1->info<<" ";

			if(node1->leftNode != NULL){
				q.enqueue(node1->leftNode);
			}

			if(node1 -> rightNode != NULL){
				q.enqueue(node1->rightNode);
			}
		}
	}
	else{
		cout<<"No node to traverse"<<endl;
	}
}

template <class T>
int BST<T>::depth(){
	Queue<treeNode<T>*> q;

	if(root != NULL){
		q.enqueue(root);
		int depth = 0,child = 0,subchild = 0;
		while(!q.isEmpty()){
			treeNode<T> *node1 = q.front();
			q.dequeue();

			if(subchild!=0){
				subchild--;
			}

			if(node1->leftNode != NULL){
				q.enqueue(node1->leftNode);
				child++;
			}

			if(node1 -> rightNode != NULL){
				q.enqueue(node1->rightNode);
				child++;
			}

			if(subchild == 0 && child != 0){
				depth++;
				subchild = child;
				child = 0;
			}

		}
		return depth;
	}
	return 0;
}

template <class T>
void BST<T>::mirror(){
	Stack<treeNode<T>*> s;

	treeNode <T> *ptr = root;

	while(ptr != NULL){
		while(ptr!= NULL){
			s.push(ptr);
			ptr = ptr->rightNode;
		}

		ptr = s.isTop();
		s.pop();
		while(ptr != NULL){
			cout<<ptr->info<<"->";
			if(ptr->leftNode != NULL){
				ptr = ptr->leftNode;
				while(ptr!= NULL){
					s.push(ptr);
					ptr = ptr->rightNode;
				}
			}
			if(!s.isEmpty()){
				ptr = s.isTop();
				s.pop();
			}
			else{
				ptr = NULL;
			}
		}
	}

}

template <class T>
void BST<T>:: parentWithChild(){
	Queue<treeNode<T>*> q;

	if(root != NULL){
		q.enqueue(root);

		while(!q.isEmpty()){
			treeNode<T> *node = q.front();
			q.dequeue();
			cout<<node->info<<": ";
			if(node->leftNode != NULL){
				cout<<node->leftNode->info<<" ";
				q.enqueue(node->leftNode);
			}

			if(node -> rightNode != NULL){
				cout<<node->rightNode->info;
				q.enqueue(node->rightNode);
			}
			cout<<endl;
		}
	}
	else{
		cout<<"No tree !!"<<endl;
	}
}

template <class T>
void BST<T>::leafNodes(){
	Queue<treeNode<T>*> q;

	if(root != NULL){
		q.enqueue(root);

		while(!q.isEmpty()){
			treeNode<T> *node = q.front();
			q.dequeue();
			if(node->leftNode == NULL && node->rightNode == NULL){
				cout<<node->info<<" ";
			}
			else{
				if(node->leftNode != NULL){
					q.enqueue(node->leftNode);
				}

				if(node -> rightNode != NULL){
					q.enqueue(node->rightNode);
				}
			}
		}
	}
	else{
		cout<<"No tree !!"<<endl;
	}
}

template <class T>
void BST<T>::copy(BST<T> t){
	Queue<treeNode<T>*> q;
	Queue<treeNode<T>*> q2;

	if(t.getRoot() != NULL){
		q.enqueue(t.getRoot());

		root = new treeNode<T>;
		root->info = t.getRoot()->info;
		q2.enqueue(root);

		treeNode<T> *ptr = root;

		while(!q.isEmpty()){

			treeNode<T> *node1 = q.front();
			q.dequeue();

			ptr = q2.front();
			q2.dequeue();

			if(node1->leftNode != NULL){
				q.enqueue(node1->leftNode);
				treeNode<T> *newNode = new treeNode<T>;
				newNode ->info = node1->leftNode->info;
				ptr->leftNode = newNode;
				q2.enqueue(newNode);

			}

			if(node1 -> rightNode != NULL){
				q.enqueue(node1->rightNode);

				treeNode<T> *newNode = new treeNode<T>;
				newNode -> info = node1->rightNode->info;
				ptr->rightNode = newNode;
				q2.enqueue(newNode);
			}

		}
	}
	else{
		cout<<"No tree to copy !!"<<endl;
	}

}

template <class T>
treeNode<T> * BST<T>::getRoot(){
	return root;
}

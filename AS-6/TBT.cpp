#include "TBT.h"
#include <iostream>

using namespace std;

template <class T>
TBT<T>::TBT() {
	root = new treeNode<T>;
	root->info = 0;
	root->left = root;
	root->right = root;
	root->leftBit = 0;
	root->rightBit = 1;
}

template <class T>
void TBT<T>::search(T ele,treeNode<T> *&loc,treeNode<T> *&par){

	treeNode<T> *ptr = root;
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
void TBT<T>::insert(T ele){

	if(root->left == root && root->right == root){
		treeNode<T> *newNode = new treeNode<T>;
		newNode->info = ele;
		newNode->left = root;
		root->left = newNode;
		root->leftBit = 1;
		newNode->right = root;
	}
	else{
		treeNode<T> *ptr = root->left;
		while(true){
			if(ele <= ptr->info){
				if(ptr->leftBit == 0){
					break;
				}
				ptr = ptr->left;
			}
			else{
				if(ptr->rightBit == 0){
					break;
				}
				ptr = ptr->right;
			}
		}
		treeNode<T> *newNode = new treeNode<T>;
		newNode->info = ele;

		if(ele <= ptr->info){
			newNode->left = ptr->left;
			ptr->leftBit = 1;
			ptr->left = newNode;
			newNode->right = ptr;
		}
		else{
			newNode->right = ptr->right;
			ptr->rightBit = 1;
			ptr->right = newNode;
			newNode->left = ptr;
		}
	}
}

template <class T>
void TBT<T>::inorderTraversal(){
	treeNode<T> *ptr = root;
	while(ptr->leftBit != 0){
		ptr = ptr->left;
	}
	if(ptr != root){
		while(ptr != root){
			cout<<ptr->info<<"->";

			if(ptr->rightBit == 0){
				ptr = ptr->right;
			}
			else{
				ptr = ptr->right;
				while(ptr->leftBit != 0){
					ptr = ptr->left;
				}
			}
		}
	}
	else{
		cout<<"The tree is empty !!"<<endl;
	}
}

template <class T>
void TBT<T>::preorderTraversal(){
	treeNode<T> *ptr = root;
	while(ptr->leftBit != 0){
		ptr = ptr->left;
		cout<<ptr->info<<"->";
	}
	if(ptr != root){
		while(ptr != root){

			if(ptr->rightBit == 0){
				ptr = ptr->right;
			}
			else{
				ptr = ptr->right;
				cout<<ptr->info<<"->";
				while(ptr->leftBit != 0){
					cout<<ptr->left->info<<"->";
					ptr = ptr->left;
				}
			}
		}
	}
	else{
		cout<<"The tree is empty !!"<<endl;
	}
}



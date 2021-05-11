#include <iostream>
#include "TBT.h"
#include "TBT.cpp"

using namespace std;

int main(){
	TBT<int> tbt;
	bool check=true;
	int c;

	while(check){
		cout<<"\n1.Insert \n2.Inorder-Traversal \n3.Preorder-Traversal \n4.Exit"<<endl;
		cin>>c;

		switch(c){
			case 1: {
				cout<<"Enter the element: ";
				int ele;
				cin>>ele;
				tbt.insert(ele);
				break;
			}

			case 2: {
				tbt.inorderTraversal();
				break;
			}

			case 3: {
				tbt.preorderTraversal();
				break;
			}

			case 4: {
				cout<<"Thank You :) "<<endl;
				break;
			}
			default: {
				cout<<"Error :( "<<endl;
			}
		}
	}
}

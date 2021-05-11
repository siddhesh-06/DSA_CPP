#include <iostream>
#include "BST.h"
#include "BST.cpp"
using namespace std;

int main(){
	BST<int> bst;
	int choice;
	do{
		cout<<"\n=============== Operations ==============="<<endl;
		cout<<"1. Insert"<<endl;
		cout<<"2. Delete"<<endl;
		cout<<"3. Search"<<endl;
		cout<<"4. Depth of tree"<<endl;
		cout<<"5. Mirror of tree"<<endl;
		cout<<"6. Parent with child"<<endl;
		cout<<"7. Leaf nodes"<<endl;
		cout<<"8. Level-wise Traverse"<<endl;
		cout<<"9. Copy a tree"<<endl;
		cout<<"10. Exit"<<endl;

		cout<<"\nEnter your choice: ";
		cin>>choice;

		switch(choice){
			case 1: {
				cout<<"Enter the element: ";
				int ele;
				cin>>ele;
				bst.insert(ele);
				break;
			}

			case 2: {
				int ele = 0;
				cout<<"Enter element: ";
				cin>>ele;
				bst.delete2(ele);
				break;
			}

			case 3: {
				cout<<"Enter element to search: ";
				int ele;
				cin>>ele;
				bst.search(ele);
				break;
			}

			case 4: {
				int depth = bst.depth();
				cout<<"Depth: "<<depth<<endl;
				break;
			}

			case 5: {
				bst.mirror();
				break;
			}

			case 6: {
				bst.parentWithChild();
				break;
			}

			case 7: {
				bst.leafNodes();
				break;
			}

			case 8: {
				bst.levelWiseTraversal();
				break;
			}

			case 9: {
				BST<int> bst2;
				bst2.copy(bst);
				bst2.levelWiseTraversal();
				break;
			}
			case 10: {
				cout<<"Thank You"<<endl;
				break;
			}
			default: {
				cout<<"Invalid credentials"<<endl;
			}
		}

	} while(choice != 10);
}

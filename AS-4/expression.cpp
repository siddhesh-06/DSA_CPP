#include <iostream>
#include "stack.cpp"
#include <cstring>


class expression{
	string exp;
	Stack<treeNode*>  s;

    public:
	void postInput(){
		cout << "Enter the postfix expression: ";
		cin >> exp;
	}

	void preInput(){
		cout << "Enter the prefix expression: ";
		cin >> exp;
	}

	bool isOperator(char c){
		if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
			return true;
		}
		else{
			return false;
		}
	}

	void postEval(){

		for (int i=0;i<exp.length();i++){
			if (isalpha(exp[i])){
                treeNode *n=new treeNode();
                n->data=exp[i];
                s.push(n);
			}
			else if(isOperator(exp[i])){
                treeNode *n=new treeNode();
                n->data=exp[i];
                n->right=s.isTop();
                s.pop();
                n->left=s.isTop();
                s.pop();
                s.push(n);
			}
		}
	}


	void preEval(){
		for (int i=(exp.length()-1);i>=0;i--){
			if (isalpha(exp[i])){
                treeNode *n=new treeNode();
                n->data=exp[i];
                s.push(n);
			}
			else if(isOperator(exp[i])){
                treeNode *n=new treeNode();
                n->data=exp[i];
                n->left=s.isTop();
                s.pop();
                n->right=s.isTop();
                s.pop();
                s.push(n);
			}
		}
	}

	void inOrderRecursive(treeNode* root){
		if (root != NULL){
			inOrder(root->left);
			cout << root->data;
			inOrder(root->right);
		}
	}

	void inOrder(treeNode* root){
		Stack<treeNode*> s;
		treeNode *ptr=root;
		while(ptr!=NULL){
			while(ptr!= NULL){
				s.push(ptr);
				ptr=ptr->left;
			}

			ptr=s.isTop();
			s.pop();
			while(ptr!=NULL){
				cout<< ptr->data;
				if(ptr->right!=NULL){
					ptr=ptr->right;
					while(ptr!=NULL){
						s.push(ptr);
						ptr=ptr->left;
					}
				}
				if(!s.isEmpty()){
					ptr=s.isTop();
					s.pop();
				}else{
					ptr=NULL;
				}

			}
		}
		}
	

	void preOrderRecursive(treeNode* root){
		if (root != NULL){
			cout << root->data;
			preOrder(root->left);
			preOrder(root->right);
		}
	}

	void preOrder(treeNode* root){
		Stack<treeNode*> s;
		treeNode *ptr=root;

		while(ptr!=NULL){
			while(ptr!=NULL){
				cout<<ptr->data;
				if(ptr->right){
					s.push(ptr->right);
				}
				ptr=ptr->left;
			}
			if(!s.isEmpty()){
				ptr=s.isTop();
				s.pop();
			}else{
				ptr=NULL;
			}
		}
	}

	void postOrderRecursive(treeNode* root){
		if (root != NULL){
			postOrder(root->left);
			postOrder(root->right);
			cout << root->data;
		}
	}

	void postOrder(treeNode* root){
		Stack<treeNode*> s1,s2;
		if(root==NULL){
			cout<<"Empty tree"<<endl;
			return;
		}
		s1.push(root);

		while(!s1.isEmpty()){
			treeNode* n1=s1.isTop();
			s1.pop();
			s2.push(n1);
			if(n1->left){
				s1.push(n1->left);
			}
			if(n1->right){
				s1.push(n1->right);
			}
		}

		while(!s2.isEmpty()){
			treeNode* n2=s2.isTop();
			s2.pop();
			cout<<n2->data;
		}
	}

	void display(){
        cout<<"Inorder: ";
        inOrder(s.isTop());
        cout<<endl;
        cout<<"Preorder: ";
        preOrder(s.isTop());
        cout<<endl;
        cout<<"Postorder: ";
        postOrder(s.isTop());
		cout<<endl;
		cout<<"=========================="<<endl;
	}

	void displayRecursive(){
        cout<<"Recursive Inorder: ";
        inOrderRecursive(s.isTop());
        cout<<endl;
        cout<<"Recursive Preorder: ";
        preOrderRecursive(s.isTop());
        cout<<endl;
        cout<<"Recursive Postorder: ";
        postOrderRecursive(s.isTop());
		cout<<endl;
		cout<<"=========================="<<endl;
	}

};


int main(){
	expression e;
	int check=1;
	while(check){
		int c{0};
		cout<<"====== Enter choice ======"<<endl;
		cout<<"1.Postfix Expression: "<<endl;
		cout<<"2.Prefix Expression: "<<endl;
		cout<<"3.Exist"<<endl;
		cin>>c;

		switch(c){
			case 1:
				e.postInput();
				e.postEval();
				e.displayRecursive();
				cout<<"===== WITHOUT RECURSION ======="<<endl;
				e.display();
				break;
			case 2:
				e.preInput();
				e.preEval();
				e.displayRecursive();
				cout<<"===== WITHOUT RECURSION ======="<<endl;
				e.display();
				break;	
			case 3:
				check=0;
				cout<<"Thank U!!"<<endl;
				break;				
			default:
				cout<<"Error"<<endl;
		}
	}
}
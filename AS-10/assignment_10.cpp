#include <iostream>
#include <fstream>
#include "File.h"
#include "File.cpp"

using namespace std;

class student {
	char name[50],address[50];
	long rollNo;
	int div;

public:

	student(){
		rollNo = 0;
		div = 0;
	}

	void input(){
		cout<<"\n================================"<<endl;
		cout<<"Enter name: ";
		cin>>name;
		cout<<"Enter address: ";
		cin>>address;
		cout<<"Enter roll no: ";
		cin>>rollNo;
		cout<<"Enter division: ";
		cin>>div;
		cout<<"================================\n"<<endl;
	}

	void display(){
		cout<<"\n---------- Student details ----------"<<endl;
		cout<<"Name: "<<name<<endl;
		cout<<"Address: "<<address<<endl;
		cout<<"Roll No: "<<rollNo<<endl;
		cout<<"Division: "<<div<<endl;
		cout<<"---------- End of Report ----------\n"<<endl;
	}

	long getRn(){
		return rollNo;
	}

};


int main(){

	int choice = 0;
	File<student> f;

	do{
		cout<<"\n1. Insert"<<endl;
		cout<<"2. Search"<<endl;
		cout<<"3. Update"<<endl;
		cout<<"4. Delete"<<endl;
		cout<<"5. Display Records"<<endl;
		cout<<"6. Exit"<<endl;

		cout<<"\nEnter your choice: ";
		cin>>choice;

		switch(choice){
			case 1: {
				student s;
				s.input();
				f.insert(s);
				break;
			}
			case 2: {
				cout<<"\nEnter Roll no.: ";
				long rn;
				cin>>rn;
				f.search(rn);
				break;
			}

			case 3: {
				cout<<"\nEnter Roll no.: ";
				long rn;
				cin>>rn;
				f.modify(rn);
				cout<<"Modified successfully :)"<<endl;
				break;
			}

			case 4: {
				cout<<"\nEnter Roll no.: ";
				long rn;
				cin>>rn;
				f.del(rn);
				cout<<"Deleted successfully"<<endl;
				break;
			}

			case 5: {
				f.displayAll();
				break;
			}

			case 6: {
				cout<<"Thank You !!"<<endl;
				break;
			}

			default: {
				cout<<"\nInvalid choice !!"<<endl;
			}
		}
	} while(choice != 6);
}

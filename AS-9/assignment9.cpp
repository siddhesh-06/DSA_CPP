#include <iostream>

using namespace std;

class heap{
public:
	void maxHeap(int arr[],int n,int item){
		n++;
		int ptr = n;
		while(ptr > 0){
			int par = (ptr - 1) / 2;
			if(item <= arr[par]){
				arr[ptr] = item;
				return;
			}
			arr[ptr] = arr[par];
			ptr = par;
		}
		arr[ptr] = item;
		return;
	}

	void minHeap(int arr[],int n,int item){
		n++;
		int ptr = n;
		while(ptr > 0){
			int par = (ptr - 1) / 2;
			if(item >= arr[par]){
				arr[ptr] = item;
				return;
			}
			arr[ptr] = arr[par];
			ptr = par;
		}
		arr[ptr] = item;
		return;
	}


	void deleteFromMaxHeap(int arr[],int n){
		int last = arr[n-1];
		n--;
		int ptr = 0,left = 1,right = 2;
		while(right<=(n-1)){
			if(last >= arr[left] && last>= arr[right]){
				arr[ptr] = last;
				return;
			}

			if(arr[right] <= arr[left]){
				arr[ptr] = arr[left];
				ptr = left;
			}
			else{
				arr[ptr] = arr[right];
				ptr = right;
			}

			left = (2 * ptr) + 1;
			right = (2 * right) + 2;
		}

		if(left == (n-1) && last < arr[left]){
			arr[ptr] = arr[left];
			ptr = left;
		}
		arr[ptr] = last;
	}

	void deleteFromMinHeap(int arr[],int n){
		int last = arr[n-1];
		n--;
		int ptr = 0,left = 1,right = 2;
		while(right<=(n-1)){
			if(last <= arr[left] && last <= arr[right]){
				arr[ptr] = last;
				return;
			}

			if(arr[right] >= arr[left]){
				arr[ptr] = arr[left];
				ptr = left;
			}
			else{
				arr[ptr] = arr[right];
				ptr = right;
			}

			left = (2 * ptr) + 1;
			right = (2 * right) + 2;
		}

		if(left == (n-1) && last > arr[left]){
			arr[ptr] = arr[left];
			ptr = left;
		}
		arr[ptr] = last;
	}

};

int main(){
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int arr[n],count = -1;
	int choice;

	int type;
	cout<<"Enter type of heap: "<<endl;
	cout<<"1.MaxHeap"<<endl;
	cout<<"2.MinHeap"<<endl;
	cout<<"\nEnter type: ";
	cin>>type;

	bool check=true;

	while(check){
		heap h;
		cout<<"1.Insert"<<endl;
		cout<<"2.Delete"<<endl;
		cout<<"3.Display"<<endl;
		cout<<"4.Exit"<<endl;
		cin>>choice;

		switch(choice){
			case 1: {
				if(count<n-1){
					int item;
					cout<<"Enter item: ";
					cin>>item;
					if(type == 1){
						h.maxHeap(arr, count, item);
					}
					else{
						h.minHeap(arr, count, item);
					}

					count++;
				}
				else{
					cout<<"\nArray is full :( "<<endl;
				}
				break;
			}

			case 2: {
				if(type == 1){
					h.deleteFromMaxHeap(arr, count+1);
				}
				else{
					h.deleteFromMinHeap(arr, count+1);
				}
				count--;
				break;
			}

			case 3: {
				for(int i=0;i<=count;i++){
					cout<<arr[i]<<" ";
				}
				cout<<"\n";
				break;
			}

			case 4: {
				check=false;
				cout<<"Thank You :) "<<endl;
				break;
			}

			default: {
				cout<<"Error :( "<<endl;
			}
		}
	}

}

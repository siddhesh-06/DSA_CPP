#include "Graph.h"
#include "Graph.cpp"
#include <iostream>

using namespace std;

int main(){

	cout<<"Enter vertices: ";
	int vertices;
	cin>>vertices;

	cout<<"Enter edges: ";
	int edges;
	cin>>edges;

	Graph g(vertices,edges);

	int choice;
	do{
		cout<<"\n1. Create Graph"<<endl;
		cout<<"2. kruskals - Minimum Spanning tree"<<endl;
		cout<<"3. Prims - Minimum Spanning tree"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<"\nEnter choice: ";

		cin>>choice;

		switch(choice){
			case 1: {
				g.createAdjacencyMatrix(vertices);
				break;
			}

			case 2: {
				int cost = g.min_spanning_tree();
				cout<<"Minimum Cost: "<<cost<<endl;
				break;
			}

			case 3: {

				cout<<"Path: "<<endl;
				int path[edges][2];
				for(int i=0;i<edges;i++){
					path[i][0] = -1;
					path[i][1] = -1;
				}
				int minCost = g.primsAlgo(path);

				for(int i=0;i<edges && path[i][0] != -1;i++){
					cout<<path[i][0]<<"->"<<path[i][1]<<endl;
				}

				cout<<"\nMinimum cost: "<<minCost<<endl;
				break;
			}

			case 4: {
				cout<<"Thank You :) "<<endl;
				break;
			}

			default: {
				cout<<"Invalid choice !!"<<endl;
			}
		}

	} while(choice != 4);
}

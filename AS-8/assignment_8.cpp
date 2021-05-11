#include <iostream>
#include "priorityQueue.h"
#include "priorityQueue.cpp"
#include "Graph.h"
#include "Graph.cpp"

using namespace std;

class node1 {
	int vertex,distance;
	bool visited;

public:
	node1(){
		vertex = -1;
		distance = 0;
		visited = false;
	};

	node1(int v){
		vertex = v;
		distance = 0;
		visited = false;
	}

	int getVertex(){
		return vertex;
	}

	void setDist(int d){
		distance = d;
	}

	int getDist(){
		return distance;
	}

	void setVisited(){
		visited = true;
	}

	bool getVisited(){
		return visited;
	}
};


int main(){

	cout<<"Enter no. of vertices: ";
	int vertices;
	cin>>vertices;

	priorityQueue<node1> pq(vertices);

	Graph g(vertices,0);
	g.createAdjacencyMatrix(vertices);

	cout<<"Enter source: ";
	int source;
	cin>>source;

	int path[vertices];
	int dist[vertices];
	int near[vertices];

	for(int i=0;i<vertices;i++){
		path[i] = (i+1);
		dist[i] = -1;
		near[i] = 1;
	}

	path[source-1] = source;
	dist[source-1] = 0;

	node1 n (source);
	n.setDist(0);
	pq.enqueue(n);

	while(!pq.isEmpty()){

		int temp_d = pq.getFront().getDist();
		int temp_v = pq.getFront().getVertex();

		pq.dequeue();
		for(int j=0;j<vertices;j++){

			if(g.getWeight(temp_v, j+1) < 999 && g.getWeight(temp_v,j+1) > 0){
				if(dist[j] == -1){
					node1 newNode(j+1);
					dist[j] = g.getWeight(temp_v, j+1) + temp_d;
					newNode.setDist(dist[j]);
					pq.enqueue(newNode);
					path[j] = temp_v;
				}
				else if(dist[j] > (g.getWeight(temp_v, j+1) + temp_d) && near[j] != 0){
					node1 newNode(j+1);
					dist[j] = g.getWeight(temp_v, j+1) + temp_d;
					newNode.setDist(dist[j]);
					pq.enqueue(newNode);
					path[j] = temp_v;
				}
			}

		}
		near[temp_v-1] = 0;
	}

	cout<<"\n============= Distance ============="<<endl;
	for(int i=0;i<vertices;i++){
		cout<<"Vertex "<<i+1<<": "<<dist[i]<<" "<<endl;;
	}

	cout<<"\n============= Path ============="<<endl;
	for(int i=0;i<vertices;i++){
		cout<<"Vertex "<<i+1<<": ";
		int temp1 = i+1;
		int temp2 = path[i];
		while(temp2 != temp1){
			cout<<temp1<<"->";
			temp1 = path[temp1 - 1];
			temp2 = path[temp1 - 1];
		}
		cout<<temp1<<endl;
	}
}

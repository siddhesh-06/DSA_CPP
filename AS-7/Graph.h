#ifndef GRAPH_H_
#define GRAPH_H_

class node {
	int u,v,w;
public:
	node(){
		u = 0;
		v = 0;
		w = 0;
	}

	friend class Graph;
};


class Graph {

	int edges,vertices;
	int **AM;

public:
	Graph(int edges,int vertices);
	void createAdjacencyMatrix(int vertices);
	int getWeight(int u,int v);
	int min_spanning_tree();
	int primsAlgo(int path[][2]);
	void display(node mst[]);
};

#endif

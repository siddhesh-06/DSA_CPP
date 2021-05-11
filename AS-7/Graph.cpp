#include "Graph.h"
#include <iostream>

using namespace std;

Graph::Graph(const int vertices, int edges)
{
	this->edges = edges;
	this->vertices = vertices;
	AM = NULL;
}

int Graph::min_spanning_tree()
{

	node *g = new node[edges];
	int count = 0;
	for (int i = 0; i < vertices; i++)
	{ //Insertion sort
		for (int j = i; j < vertices; j++)
		{
			if (i != j && AM[i][j] < 999)
			{
				node new1;
				new1.u = i + 1;
				new1.v = j + 1;
				new1.w = AM[i][j];

				int k = count - 1;
				while (k >= 0 && g[k].w > new1.w)
				{
					g[k + 1] = g[k];
					k--;
				}
				g[k + 1] = new1;
				count++;
			}
		}
	}

	node *mst = new node[vertices - 1];
	int *vertexSet = new int[vertices];

	for (int i = 0; i < vertices; i++)
	{
		vertexSet[i] = i + 1;
	}

	int min_cost = 0, edgeCount = 0;
	for (int i = 0; i < edges && edgeCount < vertices; i++)
	{
		int temp1 = g[i].u;
		int temp2 = g[i].v;

		while (temp1 != vertexSet[temp1 - 1])
		{
			temp1 = vertexSet[temp1 - 1];
		}

		while (temp2 != vertexSet[temp2 - 1])
		{
			temp2 = vertexSet[temp2 - 1];
		}

		//Loop checking
		if (temp1 != temp2)
		{
			vertexSet[temp2 - 1] = temp1;
			mst[edgeCount] = g[i];
			min_cost += g[i].w;
			edgeCount++;
		}
	}

	this->display(mst);

	return min_cost;
}

void Graph::createAdjacencyMatrix(int vertices)
{

	AM = new int *[vertices];
	for (int i = 0; i < vertices; i++)
	{
		AM[i] = new int[vertices];
	}
	for (int i = 0; i < vertices; i++)
	{
		for (int j = i; j < vertices; j++)
		{
			if (i != j)
			{
				cout << "Enter weight " << (i + 1) << "->" << (j + 1) << " :";
				cin >> AM[i][j];
				AM[j][i] = AM[i][j];
			}
			else
			{
				AM[i][j] = 0;
				AM[j][i] = 0;
			}
		}
	}
}

int Graph::primsAlgo(int path[][2])
{
	int near[vertices];

	int k = 0, l = 1;
	int minWeight = AM[0][1];
	//Min edge find
	for (int i = 0; i < vertices; i++)
	{
		for (int j = i + 1; j < vertices; j++)
		{
			if (AM[i][j] < minWeight)
			{
				minWeight = AM[i][j];
				k = i;
				l = j;
			}
		}
	}

	int minCost = AM[k][l];
	path[0][0] = k + 1;
	path[0][1] = l + 1;

	for (int i = 0; i < vertices; i++)
	{
		if (i != k && i != l)
		{
			if (AM[i][k] < AM[i][l])
			{
				near[i] = k + 1;
			}
			else
			{
				near[i] = l + 1;
			}
		}
	}

	near[k] = 0;
	near[l] = 0;

	for (int i = 2; i < vertices; i++)
	{

		int min = 999, index = 0;
		//Find min next edges
		for (int j = 0; j < vertices; j++)
		{
			if (near[j] != 0 && (AM[j][near[j] - 1] <= min))
			{
				min = AM[j][near[j] - 1];
				index = j;
			}
		}

		path[i - 1][0] = index + 1;
		path[i - 1][1] = near[index];

		minCost += AM[index][near[index] - 1];

		near[index] = 0;
		//Comparing dist min and update
		for (int m = 0; m < vertices; m++)
		{
			if (near[m] != 0 && AM[m][near[m] - 1] > AM[m][index])
			{
				near[m] = index + 1;
			}
		}
	}

	return minCost;
}

void Graph::display(node mst[])
{
	cout << "\nSpanning tree\t"
		 << "Cost" << endl;
	for (int i = 0; i < vertices - 1; i++)
	{
		cout << mst[i].u << "->" << mst[i].v << "\t\t" << mst[i].w << endl;
	}
}

int Graph::getWeight(int u, int v)
{
	if (AM != NULL)
	{
		return (AM[u - 1][v - 1]);
	}
	return NULL;
}

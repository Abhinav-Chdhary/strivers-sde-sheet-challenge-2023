#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition of the graphNode
struct graphNode
{
	int data;
	vector<graphNode *> neighbours;
	graphNode(int val) : data(val) {}
	graphNode(int val, vector<graphNode *> nbrs) : data(val), neighbours(nbrs) {}
};

// Function to perform the DFS to clone the graph
graphNode *dfs(graphNode *node, unordered_map<graphNode *, graphNode *> &um)
{
	graphNode *clone = new graphNode(node->data, vector<graphNode *>());
	um[node] = clone;
	for (auto it : node->neighbours)
	{
		if (um.find(it) == um.end())
		{
			clone->neighbours.push_back(dfs(it, um));
		}
		else
		{
			clone->neighbours.push_back(um[it]);
		}
	}
	return clone;
}

// Function to clone the graph using DFS
graphNode *cloneGraph(graphNode *node)
{
	if (!node)
		return node;
	if (node->neighbours.size() == 0)
	{
		graphNode *clone = new graphNode(node->data);
		return clone;
	}
	unordered_map<graphNode *, graphNode *> um;
	return dfs(node, um);
}

// Function to print the cloned graph
void printGraph(graphNode *node, unordered_map<graphNode *, bool> &visited)
{
	if (!node || visited[node])
		return;
	visited[node] = true;
	cout << "Node " << node->data << ": ";
	for (auto nbr : node->neighbours)
	{
		cout << nbr->data << " ";
	}
	cout << endl;
	for (auto nbr : node->neighbours)
	{
		printGraph(nbr, visited);
	}
}

// Function to clean up the memory used by the graph
void deleteGraph(graphNode *node, unordered_map<graphNode *, bool> &visited)
{
	if (!node || visited[node])
		return;
	visited[node] = true;
	for (auto nbr : node->neighbours)
	{
		deleteGraph(nbr, visited);
	}
	delete node;
}

int main()
{
	// Creating a sample graph
	graphNode *node1 = new graphNode(1);
	graphNode *node2 = new graphNode(2);
	graphNode *node3 = new graphNode(3);
	graphNode *node4 = new graphNode(4);

	node1->neighbours.push_back(node2);
	node1->neighbours.push_back(node4);
	node2->neighbours.push_back(node1);
	node2->neighbours.push_back(node3);
	node3->neighbours.push_back(node2);
	node3->neighbours.push_back(node4);
	node4->neighbours.push_back(node1);
	node4->neighbours.push_back(node3);

	// Clone the graph
	graphNode *clonedGraph = cloneGraph(node1);

	// Print the original graph
	cout << "Original Graph:\n";
	unordered_map<graphNode *, bool> visited1;
	printGraph(node1, visited1);

	// Print the cloned graph
	cout << "\nCloned Graph:\n";
	unordered_map<graphNode *, bool> visited2;
	printGraph(clonedGraph, visited2);

	// Clean up the memory used by the graphs
	unordered_map<graphNode *, bool> visited3;
	deleteGraph(node1, visited3);
	unordered_map<graphNode *, bool> visited4;
	deleteGraph(clonedGraph, visited4);

	return 0;
}

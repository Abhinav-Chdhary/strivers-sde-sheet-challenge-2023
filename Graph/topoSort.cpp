#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void toposort(vector<int> adj[], vector<int> &vis, int i, int V, vector<int> &res)
{
	vis[i] = 1;
	for (auto it : adj[i])
	{
		if (!vis[it])
		{
			toposort(adj, vis, it, V, res);
		}
	}
	res.push_back(i);
}

vector<int> topoSortDFS(int V, vector<int> adj[])
{
	vector<int> vis(V, 0);
	vector<int> res;
	for (int i = 0; i < V; i++)
	{
		if (!vis[i])
		{
			toposort(adj, vis, i, V, res);
		}
	}
	reverse(res.begin(), res.end());
	return res;
}

vector<int> topoSortKahn(int V, vector<int> adj[])
{
	vector<int> ind(V, 0), res;
	for (int i = 0; i < V; i++)
	{
		for (int x : adj[i])
		{
			ind[x]++;
		}
	}
	queue<int> q;
	for (size_t i = 0; i < V; i++)
	{
		if (ind[i] == 0)
			q.push(i);
	}
	while (!q.empty())
	{
		int curr = q.front();
		res.push_back(curr);
		q.pop();
		for (int x : adj[curr])
		{
			ind[x]--;
			if (ind[x] == 0)
				q.push(x);
		}
	}
	return res;
}

int main()
{
	int V = 6;
	vector<int> adj[V];

	// Example graph: 6 vertices, 6 edges
	adj[5].push_back(2);
	adj[5].push_back(0);
	adj[4].push_back(0);
	adj[4].push_back(1);
	adj[2].push_back(3);
	adj[3].push_back(1);

	// Topological sort using DFS
	vector<int> topoSortDfs = topoSortDFS(V, adj);
	cout << "Topological Order using DFS: ";
	for (int x : topoSortDfs)
	{
		cout << x << " ";
	}
	cout << endl;

	// Topological sort using Kahn's algorithm
	vector<int> topoSortKahn = topoSortKahn(V, adj);
	cout << "Topological Order using Kahn's algorithm: ";
	for (int x : topoSortKahn)
	{
		cout << x << " ";
	}
	cout << endl;

	return 0;
}

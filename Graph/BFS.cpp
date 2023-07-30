#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void breadthFirstSearch(int ind, vector<int> &vis, vector<int> &temp, vector<int> adjList[])
{
    queue<int> q;
    q.push(ind);
    vis[ind] = 1;
    while (!q.empty())
    {
        int curr = q.front();
        temp.push_back(curr);
        q.pop();
        for (auto it : adjList[curr])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
}

vector<int> BFS(int &V, vector<pair<int, int>> &edges)
{
    // create adjacency list
    vector<int> adjList[V];
    for (int i = 0; i < edges.size(); i++)
    {
        adjList[edges[i].first].push_back(edges[i].second);
        adjList[edges[i].second].push_back(edges[i].first);
    }
    vector<int> res;
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            breadthFirstSearch(i, vis, res, adjList);
        }
    }
    return res;
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<pair<int, int>> edges;
    cout << "Enter the edges (format: source destination):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back(make_pair(u, v));
    }

    vector<int> bfsTraversal = BFS(V, edges);

    cout << "BFS Traversal: ";
    for (int i = 0; i < bfsTraversal.size(); i++)
    {
        cout << bfsTraversal[i] << " ";
    }
    cout << endl;

    return 0;
}

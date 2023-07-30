#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(vector<int> adj[], int ind, vector<int> &vis)
{
    vis[ind] = 1;
    queue<pair<int, int>> q;
    q.push({ind, -1});
    while (!q.empty())
    {
        int cur = q.front().first;
        int src = q.front().second;
        q.pop();
        for (int it : adj[cur])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push({it, cur});
            }
            else if (it != src)
                return true;
        }
    }
    return false;
}

bool dfs(vector<int> adj[], int src, int ind, vector<int> &vis)
{
    vis[ind] = 1;
    for (int it : adj[ind])
    {
        if (!vis[it])
        {
            vis[it] = 1;
            if (dfs(adj, ind, it, vis))
                return true;
        }
        else if (it != src)
            return true;
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            if (dfs(adj, -1, i, vis))
                return true;
    }
    return false;
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices (V) and edges (E): ";
    cin >> V >> E;

    vector<int> adj[V];
    cout << "Enter the edges (u v) for the graph:\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming it is an undirected graph
    }

    bool hasCycleDFS = isCycle(V, adj);
    cout << "DFS Approach: The graph " << (hasCycleDFS ? "contains a cycle." : "does not contain a cycle.") << endl;

    // Resetting the visited array for BFS
    vector<int> vis(V, 0);
    bool hasCycleBFS = false;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (bfs(adj, i, vis))
            {
                hasCycleBFS = true;
                break;
            }
        }
    }
    cout << "BFS Approach: The graph " << (hasCycleBFS ? "contains a cycle." : "does not contain a cycle.") << endl;

    return 0;
}

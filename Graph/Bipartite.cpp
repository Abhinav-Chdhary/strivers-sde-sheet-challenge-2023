#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfsIsBipartite(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<int> vis(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (vis[i] != -1)
            continue;
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (auto x : graph[cur])
            {
                if (vis[x] == -1)
                {
                    vis[x] = !vis[cur];
                    q.push(x);
                }
                if (vis[x] == vis[cur])
                    return false;
            }
        }
    }
    return true;
}

bool dfsIsBipartite(vector<vector<int>> &graph)
{
    vector<int> vis(graph.size(), -1);
    for (int i = 0; i < vis.size(); i++)
    {
        if (vis[i] == -1)
        {
            if (!dfs(graph, i, vis, 0))
                return false;
        }
    }
    return true;
}

bool dfs(vector<vector<int>> &graph, int ind, vector<int> &vis, bool color)
{
    vis[ind] = color;
    for (auto i : graph[ind])
    {
        if (vis[i] == -1)
        {
            if (!dfs(graph, i, vis, !color))
                return false;
        }
        if (vis[i] == vis[ind])
            return false;
    }
    return true;
}

int main()
{
    vector<vector<int>> graph1 = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};       // Bipartite graph
    vector<vector<int>> graph2 = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}}; // Not bipartite graph

    cout << "Using BFS approach:" << endl;
    if (bfsIsBipartite(graph1))
        cout << "Graph1 is Bipartite." << endl;
    else
        cout << "Graph1 is not Bipartite." << endl;

    if (bfsIsBipartite(graph2))
        cout << "Graph2 is Bipartite." << endl;
    else
        cout << "Graph2 is not Bipartite." << endl;

    cout << endl
         << "Using DFS approach:" << endl;
    if (dfsIsBipartite(graph1))
        cout << "Graph1 is Bipartite." << endl;
    else
        cout << "Graph1 is not Bipartite." << endl;

    if (dfsIsBipartite(graph2))
        cout << "Graph2 is Bipartite." << endl;
    else
        cout << "Graph2 is not Bipartite." << endl;

    return 0;
}

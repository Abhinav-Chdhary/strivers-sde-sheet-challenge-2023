#include <iostream>
#include <vector>

using namespace std;

int bellmanFord(int V, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<int> dis(V + 1, 1e9);
    dis[src] = 0;
    for (int i = 1; i <= V; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if (dis[u] != 1e9 && dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                if (i == V)
                {
                    return -1;
                }
            }
        }
    }
    return dis[dest];
}

int main()
{
    int V, m, src, dest;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(3));

    cout << "Enter the edges (source, destination, weight):\n";
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    cout << "Enter the source node: ";
    cin >> src;
    cout << "Enter the destination node: ";
    cin >> dest;

    // Approach 1: Using the given bellmanFord function
    int result = bellmanFord(V, m, src, dest, edges);
    if (result == -1)
    {
        cout << "Approach 1: There is a negative cycle in the graph.\n";
    }
    else
    {
        cout << "Approach 1: Shortest distance from source to destination is " << result << endl;
    }

    return 0;
}

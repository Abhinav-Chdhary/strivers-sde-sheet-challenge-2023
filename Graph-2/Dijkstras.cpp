#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> &adj, int S)
{
    vector<int> dis(V, INT_MAX);
    vector<int> parent(V);
    for (int i = 0; i < V; i++)
        parent[i] = i;
    set<pair<int, int>> q; // pair<distance, vertex>
    dis[S] = 0;
    q.insert({0, S});
    while (!q.empty())
    {
        auto it = *(q.begin());
        int curn = it.second;
        int curd = it.first;
        q.erase(it);
        for (auto x : adj[curn])
        {
            if (curd + x[1] < dis[x[0]])
            {
                parent[x[0]] = curn;
                dis[x[0]] = curd + x[1];
                q.insert({dis[x[0]], x[0]});
            }
        }
    }
    return dis;
}

int main()
{
    int V, E, S;
    cout << "Enter the number of vertices (V): ";
    cin >> V;
    cout << "Enter the number of edges (E): ";
    cin >> E;
    cout << "Enter the source vertex (S): ";
    cin >> S;

    vector<vector<int>> adj[V];

    cout << "Enter the edges in the format: from to weight" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> shortest_distances = dijkstra(V, adj, S);

    cout << "Shortest distances from vertex " << S << " to other vertices:" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << "Vertex " << i << ": ";
        if (shortest_distances[i] == INT_MAX)
            cout << "Infinity" << endl;
        else
            cout << shortest_distances[i] << endl;
    }

    return 0;
}

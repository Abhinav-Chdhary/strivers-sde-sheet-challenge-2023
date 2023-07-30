#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //{weight, curr}
    pq.push({0, 0});
    vector<int> vis(V, 0);
    int sum = 0, i = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        int wt = it.first;
        int cur = it.second;
        pq.pop();
        if (vis[cur])
            continue;
        sum += wt;
        vis[cur] = 1;
        for (auto it : adj[cur])
        {
            if (!vis[it[0]])
            {
                pq.push({it[1], it[0]});
            }
        }
    }
    return sum;
}

// Another way of doing it
static bool comp(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
{
    return a.second <= b.second;
}

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<int> vis(n + 1, 0);
    vector<pair<pair<int, int>, int>> result;
    sort(g.begin(), g.end(), comp);
    int count = 0;
    for (int i = 0; i < m && count < n; i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int wt = g[i].second;
        if (u == v)
            continue;
        if (vis[u] && vis[v])
            continue;
        else
        {
            result.push_back(g[i]);
            vis[u] = 1;
            vis[v] = 1;
            count++;
        }
    }
    return result;
}

int main()
{
    int V = 5; // Number of vertices
    vector<vector<int>> adj[V];

    // Add edges to the graph
    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});
    adj[2].push_back({0, 6});
    adj[2].push_back({1, 3});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[3].push_back({4, 9});
    adj[4].push_back({1, 5});
    adj[4].push_back({3, 9});

    // First approach - spanningTree
    int sum = spanningTree(V, adj);
    cout << "Minimum Spanning Tree Weight (Approach 1): " << sum << endl;

    // Second approach - calculatePrimsMST
    vector<pair<pair<int, int>, int>> g;
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            int v = it[0];
            int wt = it[1];
            g.push_back({{i, v}, wt});
        }
    }
    vector<pair<pair<int, int>, int>> result = calculatePrimsMST(V, g.size(), g);
    sum = 0;
    cout << "Minimum Spanning Tree Weight (Approach 2): ";
    for (auto it : result)
    {
        cout << it.second << " ";
        sum += it.second;
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

void dfs(int ind, vector<int> &vis, vector<int> &temp, vector<int> adjList[])
{
    vis[ind] = 1;
    temp.push_back(ind);
    for (auto i : adjList[ind])
    {
        if (!vis[i])
        {
            dfs(i, vis, temp, adjList);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Create adjacency list
    vector<int> adjList[V];
    for (int i = 0; i < E; i++)
    {
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }
    vector<vector<int>> res;
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            vector<int> temp;
            dfs(i, vis, temp, adjList);
            res.push_back(temp);
        }
    }
    return res;
}

int main()
{
    int V, E;

    // Approach 1: Using a predefined set of edges
    V = 5;
    E = 4;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    vector<vector<int>> res1 = depthFirstSearch(V, E, edges1);

    cout << "Approach 1: Using a predefined set of edges\n";
    for (const auto &component : res1)
    {
        for (int node : component)
        {
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Approach 2: Taking input for edges from the user
    cout << "Approach 2: Taking input for edges from the user\n";
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    vector<vector<int>> edges2(E, vector<int>(2));
    cout << "Enter edges in the format (source, destination):\n";
    for (int i = 0; i < E; i++)
    {
        cin >> edges2[i][0] >> edges2[i][1];
    }
    vector<vector<int>> res2 = depthFirstSearch(V, E, edges2);
    for (const auto &component : res2)
    {
        for (int node : component)
        {
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Approach 3: Randomly generating edges for the graph
    cout << "Approach 3: Randomly generating edges for the graph\n";
    srand(time(0)); // Seed the random number generator with the current time
    V = 8;
    E = 10;
    vector<vector<int>> edges3(E, vector<int>(2));
    for (int i = 0; i < E; i++)
    {
        edges3[i][0] = rand() % V; // Generate random source vertex
        edges3[i][1] = rand() % V; // Generate random destination vertex
    }
    vector<vector<int>> res3 = depthFirstSearch(V, E, edges3);
    for (const auto &component : res3)
    {
        for (int node : component)
        {
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int floydWarshall(int V, int m, int src, int dest, vector<vector<int>> &edges)
{
	int n = V;
	vector<vector<int>> matrix(n + 1, vector<int>(n + 1, -1));
	for (int i = 0; i < m; i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];
		int w = edges[i][2];
		matrix[u][v] = w;
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (matrix[i][j] == -1)
				matrix[i][j] = 1e9;
			if (i == j)
				matrix[i][j] = 0;
		}
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (matrix[i][k] != 1e9 && matrix[k][j] != 1e9)
					matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
		}
	}

	/*for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(matrix[i][j]==1e9) matrix[i][j] = -1;
		}
	}*/
	return matrix[src][dest];
}

int main()
{
	int V, m, src, dest;
	cout << "Enter the number of vertices (V): ";
	cin >> V;
	cout << "Enter the number of edges (m): ";
	cin >> m;
	cout << "Enter the source vertex: ";
	cin >> src;
	cout << "Enter the destination vertex: ";
	cin >> dest;

	vector<vector<int>> edges(m, vector<int>(3));
	cout << "Enter the edges in the format (u v w):" << endl;
	for (int i = 0; i < m; i++)
	{
		cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
	}

	int shortestDistance = floydWarshall(V, m, src, dest, edges);

	if (shortestDistance == 1e9)
	{
		cout << "There is no path from source to destination." << endl;
	}
	else
	{
		cout << "Shortest distance from source to destination: " << shortestDistance << endl;
	}

	return 0;
}

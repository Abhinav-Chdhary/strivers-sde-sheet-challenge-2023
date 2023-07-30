#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int i, int j, int m, int n)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = 1;
    int dir[] = {-1, 0, 1, 0, -1};
    while (!q.empty())
    {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int x = curx + dir[k];
            int y = cury + dir[k + 1];
            if (x >= 0 && y >= 0 && x < m && y < n && !vis[x][y] && grid[x][y] == '1')
            {
                q.push({x, y});
                vis[x][y] = 1;
            }
        }
    }
}

void dfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int i, int j)
{
    if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0 || grid[i][j] == '0' || vis[i][j])
        return;
    vis[i][j] = 1;
    dfs(grid, vis, i - 1, j);
    dfs(grid, vis, i, j + 1);
    dfs(grid, vis, i + 1, j);
    dfs(grid, vis, i, j - 1);
}

int numIslands(vector<vector<char>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    int count = 0;
    vector<vector<int>> vis(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j] && grid[i][j] == '1')
            {
                count++;
                // You can choose to use either BFS or DFS here
                // bfs(grid, vis, i, j, m, n);
                dfs(grid, vis, i, j);
            }
        }
    }
    return count;
}

int main()
{
    // Sample input grid
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    int islandsCount = numIslands(grid);
    cout << "Number of islands: " << islandsCount << endl;

    return 0;
}

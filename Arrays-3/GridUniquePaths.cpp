// Recursive solution / Memoization
// t.c O(m*n), s.c 2*O(m*n)
int findPaths(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = findPaths(i - 1, j, dp);
    int left = findPaths(i, j - 1, dp);
    return dp[i][j] = up + left;
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return findPaths(m - 1, n - 1, dp);
}
// tabulation t.c O(m*n) s.c O(m*n)

int uniquePaths(int m, int n)
{
    vector<vector<int>> result(m, vector<int>(n, 1));
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            result[i][j] = result[i - 1][j] + result[i][j - 1];
        }
    }
    return result[m - 1][n - 1];
}
//tabulation space optimized
int uniquePaths(int m, int n) {
        vector<int> prev(n, 1), curr(n, 1);
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                curr[j] = curr[j-1] + prev[j];
            }
            swap(prev, curr);
        }
        return prev[n-1];
    }
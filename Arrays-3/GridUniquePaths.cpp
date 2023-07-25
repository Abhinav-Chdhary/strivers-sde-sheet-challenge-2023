#include <iostream>
#include <vector>
using namespace std;

// Recursive solution with Memoization
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

int uniquePathsMemoization(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return findPaths(m - 1, n - 1, dp);
}

// Tabulation (Dynamic Programming) with O(m*n) space complexity
int uniquePathsTabulation(int m, int n)
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

// Tabulation (Dynamic Programming) with O(n) space complexity (optimized space)
int uniquePathsTabulationOptimized(int m, int n)
{
    vector<int> prev(n, 1), curr(n, 1);
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            curr[j] = curr[j - 1] + prev[j];
        }
        swap(prev, curr);
    }
    return prev[n - 1];
}

int main()
{
    int m = 3;
    int n = 7;

    // Using Recursive solution with Memoization
    int resultMemoization = uniquePathsMemoization(m, n);
    cout << "Using Recursive solution with Memoization: " << resultMemoization << endl;

    // Using Tabulation with O(m*n) space complexity
    int resultTabulation = uniquePathsTabulation(m, n);
    cout << "Using Tabulation with O(m*n) space complexity: " << resultTabulation << endl;

    // Using Tabulation with O(n) space complexity (optimized space)
    int resultTabulationOptimized = uniquePathsTabulationOptimized(m, n);
    cout << "Using Tabulation with O(n) space complexity (optimized space): " << resultTabulationOptimized << endl;

    return 0;
}

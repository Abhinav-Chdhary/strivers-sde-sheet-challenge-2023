#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Recursive approach
int solver(int i, int j, vector<int> &arr)
{
    if (i == j)
        return 0;
    int minc = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int cost = arr[i - 1] * arr[k] * arr[j] + solver(i, k, arr) + solver(k + 1, j, arr);
        minc = min(cost, minc);
    }
    return minc;
}

int matrixMultiplicationRecursive(vector<int> &arr, int N)
{
    return solver(1, N - 1, arr);
}

// Memoization approach
int solver(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int minc = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int cost = arr[i - 1] * arr[k] * arr[j] + solver(i, k, arr, dp) + solver(k + 1, j, arr, dp);
        minc = min(cost, minc);
    }
    return dp[i][j] = minc;
}

int matrixMultiplicationMemoized(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return solver(1, N - 1, arr, dp);
}

int main()
{
    int N;
    cout << "Enter the number of matrices: ";
    cin >> N;

    vector<int> arr(N + 1);
    cout << "Enter the dimensions of matrices (N elements): ";
    for (int i = 0; i <= N; i++)
    {
        cin >> arr[i];
    }

    // Recursive approach
    int resultRecursive = matrixMultiplicationRecursive(arr, N);
    cout << "Minimum number of multiplications (Recursive): " << resultRecursive << endl;

    // Memoization approach
    int resultMemoized = matrixMultiplicationMemoized(arr, N);
    cout << "Minimum number of multiplications (Memoization): " << resultMemoized << endl;

    return 0;
}

// Binary Search dp
#include <bits/stdc++.h>
// Recursive function to find the minimum number of cuts needed to cut logs of length 'n' into 'k' parts.
int rec(int n, int k, vector<vector<int>> &dp)
{
    // Base cases
    if (n <= 0 || k <= 0)
        return 0;
    if (k == 1)
        return n;
    if (n == 1)
        return 1;

    // If the result is already calculated, return it from the DP table
    if (dp[n][k] != -1)
        return dp[n][k];

    int ans = INT_MAX;
    int low = 1;
    int high = n;

    // Perform binary search to find the optimal cut position
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Calculate the number of cuts for the left part
        int broken = rec(mid - 1, k - 1, dp);

        // Calculate the number of cuts for the right part
        int notBroken = rec(n - mid, k, dp);

        // Get the maximum cuts needed among left and right parts
        int result = max(notBroken, broken);

        // Update the answer with the minimum number of cuts needed so far
        ans = min(result + 1, ans);

        // Perform binary search by adjusting the mid point
        if (broken < notBroken)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    // Store the calculated result in the DP table
    return dp[n][k] = ans;
}

// Main function to cut logs of length 'n' into 'k' parts
int cutLogs(int k, int n)
{
    // Create a DP table with -1 as an initial value
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

    // Call the recursive function to find the minimum number of cuts
    return rec(n, k, dp);
}

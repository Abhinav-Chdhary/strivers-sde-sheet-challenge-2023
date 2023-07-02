#include <iostream>
#include <vector>

// Recursive version
void findWays(int arr[], int n, int value, int ind, long &ans) {
    if (ind >= n) {
        if (value == 0)
            ans++;
        return;
    }
    if (arr[ind] <= value) {
        findWays(arr, n, value - arr[ind], ind, ans);
    }
    findWays(arr, n, value, ind + 1, ans);
}

long countWaysToMakeChangeRecursive(int *denominations, int n, int value) {
    long ans = 0;
    findWays(denominations, n, value, 0, ans);
    if (ans == 0)
        return -1;
    return ans;
}

// Memoized version
long findWays(int arr[], int n, int value, int ind, std::vector<std::vector<long>> &dp) {
    if (value == 0) {
        return 1;
    }
    if (ind >= n) {
        return 0;
    }
    if (dp[ind][value] != -1)
        return dp[ind][value];
    long pick = 0;
    if (arr[ind] <= value)
        pick = findWays(arr, n, value - arr[ind], ind, dp);
    long notPick = findWays(arr, n, value, ind + 1, dp);
    return dp[ind][value] = pick + notPick;
}

long countWaysToMakeChangeMemoized(int *denominations, int n, int value) {
    std::vector<std::vector<long>> dp(n, std::vector<long>(value + 1, -1));
    return findWays(denominations, n, value, 0, dp);
}

int main() {
    int denominations[] = {1, 2, 3};
    int n = sizeof(denominations) / sizeof(denominations[0]);
    int value = 4;

    long resultRecursive = countWaysToMakeChangeRecursive(denominations, n, value);
    long resultMemoized = countWaysToMakeChangeMemoized(denominations, n, value);

    std::cout << "Recursive: " << resultRecursive << std::endl;
    std::cout << "Memoized: " << resultMemoized << std::endl;

    return 0;
}

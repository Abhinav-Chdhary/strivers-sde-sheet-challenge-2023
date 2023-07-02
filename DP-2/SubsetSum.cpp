#include <iostream>
#include <vector>

// Recursive version
bool findWays(std::vector<int> &arr, int n, int value, int ind) {
    if (value == 0) {
        return true;
    }
    if (ind >= n) {
        return false;
    }
    bool pick = false;
    if (arr[ind] <= value)
        pick = findWays(arr, n, value - arr[ind], ind + 1);
    bool notPick = findWays(arr, n, value, ind + 1);
    return (pick || notPick);
}

bool subsetSumToKRecursive(int n, int k, std::vector<int> &arr) {
    return findWays(arr, n, k, 0);
}

// Memoized version
bool findWays(std::vector<int> &arr, int n, int value, int ind, std::vector<std::vector<int>> &dp) {
    if (value == 0) {
        return true;
    }
    if (ind >= n) {
        return false;
    }
    if (dp[ind][value] != -1)
        return dp[ind][value];
    bool pick = false;
    if (arr[ind] <= value)
        pick = findWays(arr, n, value - arr[ind], ind + 1, dp);
    bool notPick = findWays(arr, n, value, ind + 1, dp);
    return dp[ind][value] = (pick || notPick);
}

bool subsetSumToKMemoized(int n, int k, std::vector<int> &arr) {
    std::vector<std::vector<int>> dp(n, std::vector<int>(k + 1, -1));
    return findWays(arr, n, k, 0, dp);
}

int main() {
    std::vector<int> arr = {2, 4, 6, 8};
    int n = arr.size();
    int k = 14;

    bool resultRecursive = subsetSumToKRecursive(n, k, arr);
    bool resultMemoized = subsetSumToKMemoized(n, k, arr);

    std::cout << "Recursive: " << (resultRecursive ? "Yes" : "No") << std::endl;
    std::cout << "Memoized: " << (resultMemoized ? "Yes" : "No") << std::endl;

    return 0;
}

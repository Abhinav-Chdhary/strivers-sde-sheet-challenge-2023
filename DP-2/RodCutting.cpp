#include <iostream>
#include <vector>
#include <algorithm>

// Recursive version
int maxCost(std::vector<int> &prices, int ind, int n) {
    if (ind == 0) {
        return n * prices[0];
    }
    int notTake = 0 + maxCost(prices, ind - 1, n);
    int take = 0;
    if (ind + 1 <= n) {
        take = prices[ind] + maxCost(prices, ind, n - ind - 1);
    }
    return std::max(take, notTake);
}

int cutRodRecursive(std::vector<int> &price, int n) {
    return maxCost(price, n - 1, n);
}

// Memoized version
int maxCost(std::vector<int> &prices, int ind, int n, std::vector<std::vector<int>> &dp) {
    if (ind == 0) {
        return n * prices[0];
    }
    if (dp[ind][n] != -1)
        return dp[ind][n];
    int notTake = 0 + maxCost(prices, ind - 1, n, dp);
    int take = 0;
    if (ind + 1 <= n) {
        take = prices[ind] + maxCost(prices, ind, n - ind - 1, dp);
    }
    return dp[ind][n] = std::max(take, notTake);
}

int cutRodMemoized(std::vector<int> &price, int n) {
    std::vector<std::vector<int>> dp(n, std::vector<int>(n + 1, -1));
    return maxCost(price, n - 1, n, dp);
}

// Tabulation version
int cutRodTabulation(std::vector<int> &price, int n) {
    std::vector<std::vector<int>> dp(n, std::vector<int>(n + 1, -1));

    for (int i = 0; i <= n; i++) {
        dp[0][i] = i * price[0];
    }

    for (int ind = 1; ind < n; ind++) {
        for (int length = 0; length <= n; length++) {
            int notTaken = 0 + dp[ind - 1][length];
            int taken = 0;
            if (ind + 1 <= length)
                taken = price[ind] + dp[ind][length - ind - 1];
            dp[ind][length] = std::max(notTaken, taken);
        }
    }

    return dp[n - 1][n];
}

int main() {
    std::vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = price.size();

    int resultRecursive = cutRodRecursive(price, n);
    int resultMemoized = cutRodMemoized(price, n);
    int resultTabulation = cutRodTabulation(price, n);

    std::cout << "Recursive: " << resultRecursive << std::endl;
    std::cout << "Memoized: " << resultMemoized << std::endl;
    std::cout << "Tabulation: " << resultTabulation << std::endl;

    return 0;
}

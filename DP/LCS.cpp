#include <iostream>
#include <vector>
using namespace std;

// Recursive solution without DP: O(2^n)
int lcsRecursive(string &text1, string &text2, int i, int j)
{
    if (i < 0 || j < 0)
        return 0;
    else if (text1[i] == text2[j])
        return 1 + lcsRecursive(text1, text2, i - 1, j - 1);
    else
        return max(lcsRecursive(text1, text2, i - 1, j), lcsRecursive(text1, text2, i, j - 1));
}

// Dynamic Programming solution: O(n*m)
int lcsDP(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    else if (dp[i][j] != -1)
        return dp[i][j];
    else if (text1[i] == text2[j])
        return dp[i][j] = 1 + lcsDP(text1, text2, i - 1, j - 1, dp);
    else
        return dp[i][j] = max(lcsDP(text1, text2, i - 1, j, dp), lcsDP(text1, text2, i, j - 1, dp));
}

int longestCommonSubsequence(string text1, string text2)
{
    int n1 = text1.size(), n2 = text2.size();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    return lcsDP(text1, text2, n1 - 1, n2 - 1, dp);
}

int main()
{
    string text1 = "abcde";
    string text2 = "ace";

    // Approach 1: Recursive solution without DP
    int resultRecursive = lcsRecursive(text1, text2, text1.size() - 1, text2.size() - 1);
    cout << "Longest Common Subsequence (Recursive): " << resultRecursive << endl;

    // Approach 2: Dynamic Programming solution
    int resultDP = longestCommonSubsequence(text1, text2);
    cout << "Longest Common Subsequence (DP): " << resultDP << endl;

    return 0;
}

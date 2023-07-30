#include <iostream>
#include <vector>
using namespace std;

int sequencer(vector<int> &nums, int ind, int prev, int n, vector<vector<int>> &dp);

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return sequencer(nums, 0, -1, n, dp);
}

int sequencer(vector<int> &nums, int ind, int prev, int n, vector<vector<int>> &dp)
{
    if (ind >= n)
        return 0;
    if (dp[ind][prev + 1] != -1)
        return dp[ind][prev + 1];

    int notTake = 0 + sequencer(nums, ind + 1, prev, n, dp);
    int take = 0;
    if (prev == -1 || nums[ind] > nums[prev])
    {
        take = 1 + sequencer(nums, ind + 1, ind, n, dp);
    }
    return dp[ind][prev + 1] = max(take, notTake);
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int result = lengthOfLIS(nums);
    cout << "Length of the Longest Increasing Subsequence: " << result << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int pro = 1, PrefixMax = INT_MIN, SuffixMax = INT_MIN;
    bool zeroFlag = false;

    // Prefix max product
    for (int x : nums)
    {
        if (x == 0)
        {
            pro = 1;
            zeroFlag = true;
            continue;
        }
        pro *= x;
        PrefixMax = max(PrefixMax, pro);
    }

    pro = 1;
    // Suffix max product
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int x = nums[i];
        if (x == 0)
        {
            pro = 1;
            zeroFlag = true;
            continue;
        }
        pro *= x;
        SuffixMax = max(SuffixMax, pro);
    }

    if (zeroFlag)
        return max(0, max(PrefixMax, SuffixMax));

    return max(PrefixMax, SuffixMax);
}

// Brute force approach: Generate all subarrays and calculate the sum
int maxProductBrute(vector<int> &nums)
{
    int n = nums.size();
    int maxProduct = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int pro = 1;
        for (int j = i; j < n; j++)
        {
            pro *= nums[j];
            maxProduct = max(maxProduct, pro);
        }
    }

    return maxProduct;
}

int main()
{
    vector<int> nums = {2, 3, -2, 4}; // You can change the array elements here

    // Approach 1: Optimal
    int optimalMaxProduct = maxProduct(nums);
    cout << "Optimal Max Product: " << optimalMaxProduct << endl;

    // Approach 2: Brute Force
    int bruteMaxProduct = maxProductBrute(nums);
    cout << "Brute Force Max Product: " << bruteMaxProduct << endl;

    return 0;
}

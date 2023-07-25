#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// Function to find all pairs in the vector that sum up to the target
vector<vector<int>> pairSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); i++)
    {
        int part = nums.at(i);
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (part + nums.at(j) > target)
                break;
            if (part + nums.at(j) == target)
            {
                res.push_back({nums[i], nums[j]});
            }
        }
    }
    return res;
}

// Function to find the indices of two numbers that sum up to the target
vector<int> twoSum(vector<int> &nums, int target)
{
    map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        if (m.find(target - nums[i]) != m.end())
            return {m[target - nums[i]], i};
        m[nums[i]] = i;
    }
    return {0, 0};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15}; // Example input
    int target = 9;                    // Example target

    // Using pairSum function to find pairs that sum up to the target
    vector<vector<int>> pairs = pairSum(nums, target);
    cout << "Pairs that sum up to the target (" << target << "): ";
    for (auto pair : pairs)
    {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;

    // Using twoSum function to find the indices of two numbers that sum up to the target
    vector<int> indices = twoSum(nums, target);
    cout << "Indices of two numbers that sum up to the target (" << target << "): ";
    for (int idx : indices)
    {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}

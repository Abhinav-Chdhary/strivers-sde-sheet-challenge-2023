#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> majorityElementHashing(vector<int> &nums)
{
    unordered_map<int, int> um;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        um[nums[i]]++;
    }
    int must = nums.size() / 3;
    for (auto it : um)
    {
        if (it.second > must)
            res.push_back(it.first);
    }
    return res;
}

vector<int> majorityElementMoore(vector<int> &nums)
{
    int cand1 = INT_MIN, cand2 = INT_MIN;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (c1 == 0 && nums[i] != cand2)
        {
            c1 = 1;
            cand1 = nums[i];
        }
        else if (c2 == 0 && nums[i] != cand1)
        {
            c2 = 1;
            cand2 = nums[i];
        }
        else if (cand1 == nums[i])
            c1++;
        else if (cand2 == nums[i])
            c2++;
        else
        {
            c1--;
            c2--;
        }
    }
    vector<int> res;
    c1 = 0;
    c2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (cand1 == nums[i])
            c1++;
        else if (cand2 == nums[i])
            c2++;
    }
    int must = nums.size() / 3 + 1;
    if (c1 >= must)
        res.push_back(cand1);
    if (c2 >= must)
        res.push_back(cand2);
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    vector<int> nums = {3, 1, 2, 2, 1, 2, 3, 3}; // Example input

    // Using Hashing approach
    vector<int> majorityElementsHashing = majorityElementHashing(nums);
    cout << "Using Hashing approach, Majority elements are: ";
    for (int elem : majorityElementsHashing)
    {
        cout << elem << " ";
    }
    cout << endl;

    // Using Modified Moore's Voting algorithm
    vector<int> majorityElementsMoore = majorityElementMoore(nums);
    cout << "Using Modified Moore's Voting algorithm, Majority elements are: ";
    for (int elem : majorityElementsMoore)
    {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}

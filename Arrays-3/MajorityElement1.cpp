#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int candidate = nums[0];
    int count = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == candidate)
            count++;
        else
        {
            count--;
            if (count == 0)
            {
                count = 1;
                candidate = nums[i];
            }
        }
    }
    return candidate;
}

int main()
{
    vector<int> nums = {3, 3, 4, 2, 4, 4, 2, 4, 4}; // Example input

    int majority = majorityElement(nums);
    cout << "The majority element is: " << majority << endl;

    return 0;
}

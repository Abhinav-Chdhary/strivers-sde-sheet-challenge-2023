#include <iostream>

using namespace std;

int search(int *nums, int n, int target)
{
    int lo = 0, hi = n - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[lo] <= nums[mid])
        {
            // Left side is sorted
            if (target >= nums[lo] && target < nums[mid])
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        else if (nums[lo] >= nums[mid])
        {
            // Right side is sorted
            if (target > nums[mid] && target <= nums[hi])
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int nums[] = {4, 5, 6, 7, 8, 9, 0, 1, 2, 3};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 6;

    int result = search(nums, n, target);

    if (result != -1)
    {
        std::cout << "Element found at index: " << result << std::endl;
    }
    else
    {
        std::cout << "Element not found." << std::endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

// Brute force approach - O(n^2)
int reversePairsBruteForce(vector<int> &nums)
{
    int n = nums.size(), count = 0;
    for (int j = n - 1; j >= 0; j--)
    {
        for (int i = j - 1; i >= 0; i--)
        {
            if (nums[i] > (long)2 * nums[j])
                count++;
        }
    }
    return count;
}

// Helper function to count the number of valid pairs in the merged array
int countPairs(vector<int> &arr, int l, int mid, int r)
{
    int count = 0, right = mid + 1;
    for (int i = l; i <= mid; i++)
    {
        // Finding the number of pairs where arr[i] > 2 * arr[right]
        while (right <= r && arr[i] > (long)2 * arr[right])
            right++;
        count += (right - (mid + 1)); // Incrementing the count with the number of valid pairs
    }
    return count;
}

// Helper function to merge two sorted subarrays
void merge(vector<int> &nums, int l, int mid, int r)
{
    int i = l, j, k, m = (mid - l) + 1, n = r - mid;
    j = k = 0;
    vector<int> arr1(m, 0), arr2(n, 0);

    // Creating two temporary arrays to store the subarrays
    for (j = 0; j < m; j++)
    {
        arr1[j] = nums[i++];
    }
    for (k = 0; k < n; k++)
    {
        arr2[k] = nums[i++];
    }

    j = k = 0;
    i = l;

    // Merging the two subarrays in sorted order
    while (j < m && k < n)
    {
        if (arr1[j] <= arr2[k])
        {
            nums[i++] = arr1[j++];
        }
        else
        {
            nums[i++] = arr2[k++];
        }
    }

    // Copying the remaining elements from the first subarray
    while (j < m)
    {
        nums[i++] = arr1[j++];
    }

    // Copying the remaining elements from the second subarray
    while (k < n)
    {
        nums[i++] = arr2[k++];
    }
}

// Merge sort with counting of reverse pairs - O(nlogn)
int mergeSortCountReversePairs(vector<int> &nums, int l, int r)
{
    int count = 0;
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        // Recursively divide the array into two halves and merge them
        count += mergeSortCountReversePairs(nums, l, mid);
        count += mergeSortCountReversePairs(nums, mid + 1, r);

        // Count the number of reverse pairs in the merged array
        count += countPairs(nums, l, mid, r);

        // Merge the two sorted subarrays
        merge(nums, l, mid, r);
    }
    return count;
}

int reversePairs(vector<int> &nums)
{
    int n = nums.size();
    return mergeSortCountReversePairs(nums, 0, n - 1);
}

int main()
{
    vector<int> nums = {1, 3, 2, 3, 1}; // Example input

    // Using Brute force approach
    int resultBruteForce = reversePairsBruteForce(nums);
    cout << "Using Brute force approach, Number of reverse pairs: " << resultBruteForce << endl;

    // Using Optimal Merge sort approach
    int resultMergeSort = reversePairs(nums);
    cout << "Using Merge sort approach, Number of reverse pairs: " << resultMergeSort << endl;

    return 0;
}

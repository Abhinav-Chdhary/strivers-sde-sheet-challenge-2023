// Brute force t.c => O(n^2)
int reversePairs(vector<int> &nums)
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
// Optimal using Merge sort O(nlogn)
int countPairs(vector<int> &arr, int l, int mid, int r){
    int count = 0, right = mid+1;
    for(int i=l; i<=mid; i++){
        // Finding the number of pairs where arr[i] > 2*arr[right]
        while(right<=r && arr[i]>(long)2*arr[right]) right++;
        count += (right-(mid+1)); // Incrementing the count with the number of valid pairs
    }
    return count;
}

void merger(vector<int> &nums, int l, int mid, int r) {
    int i = l, j, k, m = (mid - l) + 1, n = r - mid;
    j = k = 0;
    vector<int> arr1(m, 0), arr2(n, 0);
    
    // Creating two temporary arrays to store the subarrays
    for (j = 0; j < m; j++) {
        arr1[j] = nums[i++];
    }
    for (k = 0; k < n; k++) {
        arr2[k] = nums[i++];
    }
    
    j = k = 0;
    i = l;
    
    // Merging the two subarrays in sorted order
    while (j < m && k < n) {
        if (arr1[j] <= arr2[k]) {
            nums[i++] = arr1[j++];
        } else {
            nums[i++] = arr2[k++];
        }
    }
    
    // Copying the remaining elements from the first subarray
    while (j < m) {
        nums[i++] = arr1[j++];
    }
    
    // Copying the remaining elements from the second subarray
    while (k < n) {
        nums[i++] = arr2[k++];
    }
}

int mergeSort(vector<int> &nums, int l, int r) {
    int count = 0;
    if (l < r) {
        int mid = l + (r - l) / 2;
        // Recursively divide the array into two halves and merge them
        count += mergeSort(nums, l, mid);
        count += mergeSort(nums, mid + 1, r);
        
        // Count the number of reverse pairs in the merged array
        count += countPairs(nums, l, mid, r);
        
        // Merge the two sorted subarrays
        merger(nums, l, mid, r);
    }
    return count;
}

int reversePairs(vector<int> &nums)
{
    int n = nums.size();
    return mergeSort(nums, 0, n - 1);
}
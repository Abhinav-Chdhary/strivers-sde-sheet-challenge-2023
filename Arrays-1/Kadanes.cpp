#include <iostream>
#include <climits>

using namespace std;

//Kadane's algo
long long maxSubarraySum(int arr[], int n)
{
    long long res = LONG_MIN, sum = 0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        res = max(res, sum);
        if(sum<0) sum=0;
    }
    return res>0?res:0;
}
int main() {
    // Example usage
    int arr[] = {1, -2, 3, 4, -5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Compute the maximum subarray sum
    long long maxSum = maxSubarraySum(arr, size);

    // Print the result
    cout << "Maximum subarray sum: " << maxSum << endl;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

// Brute force approach to find the median of two sorted arrays
double medianBruteForce(vector<int> &a, vector<int> &b)
{
    int n = a.size(), m = b.size();
    vector<int> merger(n + m);
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
            merger[k++] = a[i++];
        else
            merger[k++] = b[j++];
    }
    while (i < n)
    {
        merger[k++] = a[i++];
    }
    while (j < m)
    {
        merger[k++] = b[j++];
    }
    double res = 0;
    n = merger.size() - 1;
    if (merger.size() % 2)
        res = static_cast<double>(merger[n / 2]);
    else
        res = static_cast<double>(merger[n / 2] + merger[n / 2 + 1]) / 2;

    return res;
}

// Optimal approach to find the median of two sorted arrays
double findMedianSortedArrays(vector<int> &a, vector<int> &b)
{
    int n = a.size(), m = b.size();
    if (m < n)
        return findMedianSortedArrays(b, a);
    int l = 0, r = n;
    while (l <= r)
    {
        int p1 = l + (r - l) / 2;      // partition of smaller array
        int p2 = (n + m + 1) / 2 - p1; // partition of bigger array

        // If all elements of 'a' are greater than all elements of 'b'
        // then set l1 = -inf else
        int l1 = p1 == 0 ? INT_MIN : a[p1 - 1];
        // Similarly for p2 partition
        int l2 = p2 == 0 ? INT_MIN : b[p2 - 1];

        // If all elements of 'a' are less than all elements of 'b'
        // then set r1 = +inf else
        int r1 = p1 == n ? INT_MAX : a[p1];
        // Similarly for p2 partition
        int r2 = p2 == m ? INT_MAX : b[p2];

        if (l1 <= r2 && l2 <= r1)
        {
            // If length of merger array is odd
            if ((n + m) % 2)
                return static_cast<double>(max(l1, l2));
            // If even
            else
                return static_cast<double>(max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if (l1 > r2)
            r = p1 - 1;
        else
            l = p1 + 1;
    }
    return 0.0;
}

int main()
{
    vector<int> arr1 = {1, 3, 5};
    vector<int> arr2 = {2, 4, 6};

    cout << "Using Brute Force Approach: Median = " << medianBruteForce(arr1, arr2) << endl;
    cout << "Using Optimal Approach: Median = " << findMedianSortedArrays(arr1, arr2) << endl;

    return 0;
}

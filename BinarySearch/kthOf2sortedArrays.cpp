#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Brute force O(n+m) approach
int ninjaAndLadoos_BruteForce(vector<int> &row1, vector<int> &row2, int m, int n, int k)
{
    int i = 0, j = 0, ans = -1;
    while (i < m && j < n)
    {
        if (row1[i] <= row2[j])
        {
            ans = row1[i++];
            k--;
        }
        else
        {
            ans = row2[j++];
            k--;
        }
        if (k == 0)
            return ans;
    }
    while (i < m)
    {
        ans = row1[i++];
        k--;
        if (k == 0)
            return ans;
    }
    while (j < n)
    {
        ans = row2[j++];
        k--;
        if (k == 0)
            return ans;
    }
    return -1;
}

// Optimal using binary search O(log(n+m)) approach
int ninjaAndLadoos_BinarySearch(vector<int> &row1, vector<int> &row2, int m, int n, int k)
{
    if (m > n)
        return ninjaAndLadoos_BinarySearch(row2, row1, n, m, k);
    long l = max(0, k - n), r = min(k, m);
    while (l <= r)
    {
        int p1 = l + (r - l) / 2; // partition of smaller array
        int p2 = k - p1;          // partition of bigger array
        // if all elements of 'a' are greater than all elements of 'b'
        // then set l1 = -inf else
        int l1 = p1 == 0 ? INT_MIN : row1[p1 - 1];
        // similarly for p2 partition
        int l2 = p2 == 0 ? INT_MIN : row2[p2 - 1];
        // if all elements of 'a' are less than all elements of 'b'
        // then set r1 = +inf else
        int r1 = p1 == m ? INT_MAX : row1[p1];
        // similarly for p2 partition
        int r2 = p2 == n ? INT_MAX : row2[p2];

        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l1 > r2)
            r = p1 - 1;
        else
            l = p1 + 1;
    }
    return 1;
}

int main()
{
    // Test the functions with sample inputs
    vector<int> row1 = {2, 5, 8, 12};
    vector<int> row2 = {4, 7, 9, 11, 15};
    int m = row1.size();
    int n = row2.size();
    int k = 7;

    // Brute force approach
    int resultBruteForce = ninjaAndLadoos_BruteForce(row1, row2, m, n, k);
    cout << "Brute Force Approach: " << resultBruteForce << endl;

    // Optimal binary search approach
    int resultBinarySearch = ninjaAndLadoos_BinarySearch(row1, row2, m, n, k);
    cout << "Binary Search Approach: " << resultBinarySearch << endl;

    return 0;
}

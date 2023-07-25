#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Brute force approach
int subarraysXorBruteForce(vector<int> &arr, int x)
{
    int cnt = 0, n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int mask = 0;
        for (int j = i; j < n; j++)
        {
            mask = (mask ^ arr[j]);
            if (mask == x)
                cnt++;
        }
    }
    return cnt;
}

// Optimal approach
int subarraysXorOptimal(vector<int> &arr, int k)
{
    int cnt = 0, n = arr.size();
    unordered_map<int, int> um;
    int xr = 0;
    um[0]++;
    for (int i = 0; i < n; i++)
    {
        xr ^= arr[i];

        if (um.find(xr ^ k) != um.end())
        {
            cnt += um[xr ^ k];
        }
        um[xr]++;
    }
    return cnt;
}

int main()
{
    vector<int> arr = {4, 2, 2, 6, 4};
    int x = 6;
    int k = 6;

    // Using Brute force approach
    int resultBruteForce = subarraysXorBruteForce(arr, x);
    cout << "Using Brute force approach: " << resultBruteForce << " subarrays with XOR value " << x << endl;

    // Using Optimal approach
    int resultOptimal = subarraysXorOptimal(arr, k);
    cout << "Using Optimal approach: " << resultOptimal << " subarrays with XOR value " << k << endl;

    return 0;
}

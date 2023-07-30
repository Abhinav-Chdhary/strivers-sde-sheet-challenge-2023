#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Brute force nearly O(n^2)
vector<int> countDistinctElements_brute(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> ans;
    for (int i = 0; i <= n - k; i++)
    {
        unordered_set<int> s;
        for (int j = i; j < i + k; j++)
        {
            s.insert(arr[j]);
        }
        ans.push_back(s.size());
    }
    return ans;
}

// Better O(k+n) and s.c O(n)
vector<int> countDistinctElements_optimized(vector<int> &arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> freq;
    vector<int> ans;
    int count = 0;
    for (int i = 0; i < k; i++)
    {
        if (freq[arr[i]] == 0)
        {
            count++;
        }
        freq[arr[i]]++;
    }
    ans.push_back(count);
    for (int i = k; i < n; i++)
    {
        freq[arr[i - k]]--;
        if (freq[arr[i - k]] == 0)
            count--;
        if (freq[arr[i]] == 0)
            count++;
        freq[arr[i]]++;
        ans.push_back(count);
    }
    return ans;
}

int main()
{
    // Sample input
    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
    int k = 3;

    // Using the brute force version of the function
    vector<int> result_brute = countDistinctElements_brute(arr, k);
    cout << "Brute force result:" << endl;
    for (int i : result_brute)
    {
        cout << i << " ";
    }
    cout << endl;

    // Using the optimized version of the function
    vector<int> result_optimized = countDistinctElements_optimized(arr, k);
    cout << "Optimized result:" << endl;
    for (int i : result_optimized)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

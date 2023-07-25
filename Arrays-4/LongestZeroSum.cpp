#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Brute force O(n^2) approach
int LongestSubsetWithZeroSumBruteForce(vector<int> arr)
{
  int ans = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    int sum = 0;
    for (int j = i; j < arr.size(); j++)
    {
      sum += arr[j];
      if (sum == 0)
        ans = max(ans, j - i + 1);
    }
  }
  return ans;
}

// Optimal using prefix sum approach
int LongestSubsetWithZeroSumOptimal(vector<int> arr)
{
  unordered_map<int, int> um;
  int ans = 0, sum = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    sum += arr[i];
    if (sum == 0)
      ans = i + 1;
    else
    {
      if (um.find(sum) != um.end())
      {
        ans = max(ans, i - um[sum]);
      }
      else
      {
        um[sum] = i;
      }
    }
  }
  return ans;
}

int main()
{
  vector<int> arr = {4, 2, -3, 1, 6}; // Example input

  // Using Brute force O(n^2) approach
  int longestSubsetBrute = LongestSubsetWithZeroSumBruteForce(arr);
  cout << "Using Brute force O(n^2) approach, Longest subset with zero sum: " << longestSubsetBrute << endl;

  // Using Optimal prefix sum approach
  int longestSubsetOptimal = LongestSubsetWithZeroSumOptimal(arr);
  cout << "Using Optimal prefix sum approach, Longest subset with zero sum: " << longestSubsetOptimal << endl;

  return 0;
}

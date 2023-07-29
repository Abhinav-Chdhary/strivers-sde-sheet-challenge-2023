#include <iostream>
#include <cmath>
using namespace std;

// Brute force approach O(sqrt(m)) or O(sqrt(m)*log(N)) if we consider t.c of pow function.
int NthRootBruteForce(int n, int m)
{
  if (n == 1)
    return m;
  for (int i = 1; i <= sqrt(m); i++)
  {
    if ((long long)pow(i, n) == m)
      return i;
  }
  return -1;
}

// Optimal binary search approach O(logn)
int calMid(int n, int m, int mid)
{
  long long ans = 1;
  while (n-- > 0)
  {
    ans *= mid;
    if (ans > m)
      return 0;
  }
  if (ans == m)
    return 1;
  return 2;
}

int NthRootBinarySearch(int n, int m)
{
  if (n == 1)
    return m;
  int l = 1, r = m;
  while (l <= r)
  {
    int mid = l + (r - l) / 2;
    int flag = calMid(n, m, mid);
    if (flag == 1)
    {
      return mid;
    }
    else if (flag == 0)
    {
      r = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
  }
  return -1;
}

int main()
{
  int n, m;
  cout << "Enter the value of n: ";
  cin >> n;
  cout << "Enter the value of m: ";
  cin >> m;

  // Brute force approach
  int resultBruteForce = NthRootBruteForce(n, m);
  if (resultBruteForce != -1)
  {
    cout << "Nth root using brute force: " << resultBruteForce << endl;
  }
  else
  {
    cout << "No Nth root found using brute force." << endl;
  }

  // Binary search approach
  int resultBinarySearch = NthRootBinarySearch(n, m);
  if (resultBinarySearch != -1)
  {
    cout << "Nth root using binary search: " << resultBinarySearch << endl;
  }
  else
  {
    cout << "No Nth root found using binary search." << endl;
  }

  return 0;
}

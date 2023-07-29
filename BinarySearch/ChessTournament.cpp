#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Approach 1: Greedy O(nlogn) - Wrong answer
int chessTournamentGreedy(vector<int> posi, int n, int c)
{
	sort(posi.begin(), posi.end());
	int pans = abs(posi[0] - posi[n - 1]);
	return (pans / (c - 1));
}

// Approach 2: Brute Force O(nlogn+n*m)
bool isValidBruteForce(vector<int> &posi, int gap, int n, int c)
{
	int lastPut = posi[0];
	c--;
	for (int i = 1; i < n; i++)
	{
		if (posi[i] >= lastPut + gap)
		{
			c--;
			lastPut = posi[i];
		}
	}
	if (c > 0)
		return false;
	return true;
}

int chessTournamentBruteForce(vector<int> posi, int n, int c)
{
	sort(posi.begin(), posi.end());
	int limit = posi[n - 1] - posi[0];
	int ans = -1;
	for (int i = 1; i <= limit; i++)
	{
		if (isValidBruteForce(posi, i, n, c))
		{
			ans = i;
		}
	}
	return ans;
}

// Approach 3: Optimal using Binary Search O(nlogn+n*log(m))
bool isValidBinarySearch(vector<int> &posi, int gap, int n, int c)
{
	int lastPut = posi[0];
	c--;
	for (int i = 1; i < n; i++)
	{
		if (posi[i] >= lastPut + gap)
		{
			c--;
			lastPut = posi[i];
		}
	}
	if (c > 0)
		return false;
	return true;
}

int chessTournamentBinarySearch(vector<int> posi, int n, int c)
{
	sort(posi.begin(), posi.end());
	int l = 1, r = posi[n - 1] - posi[0];
	int ans = 1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (isValidBinarySearch(posi, mid, n, c))
		{
			ans = max(ans, mid);
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	return ans;
}

int main()
{
	int n, c;
	cout << "Enter the number of players: ";
	cin >> n;

	vector<int> positions(n);
	cout << "Enter the positions of players: ";
	for (int i = 0; i < n; i++)
	{
		cin >> positions[i];
	}

	cout << "Enter the number of allowed vacancies (c): ";
	cin >> c;

	// Approach 1: Greedy
	int ansGreedy = chessTournamentGreedy(positions, n, c);
	cout << "Greedy Approach: " << ansGreedy << " vacancies needed." << endl;

	// Approach 2: Brute Force
	int ansBruteForce = chessTournamentBruteForce(positions, n, c);
	cout << "Brute Force Approach: " << ansBruteForce << " vacancies needed." << endl;

	// Approach 3: Optimal Binary Search
	int ansBinarySearch = chessTournamentBinarySearch(positions, n, c);
	cout << "Optimal Binary Search Approach: " << ansBinarySearch << " vacancies needed." << endl;

	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

// Recurrence relation (Naive Recursive)
int sequencer(vector<int> &rack, int ind, int cur, int prev)
{
	if (ind >= rack.size())
	{
		return 0;
	}
	int not_pick = 0 + sequencer(rack, ind + 1, cur, prev);
	int pick = 0;
	if (rack[ind] > prev)
	{
		pick = rack[ind] + sequencer(rack, ind + 1, cur + rack[ind], rack[ind]);
	}
	return max(pick, not_pick);
}

int maxIncreasingDumbbellsSumNaive(vector<int> &rack, int n)
{
	return sequencer(rack, 0, 0, -1);
}

// Using Memoization
int sequencer(vector<int> &rack, int ind, int cur, int prev, vector<vector<int>> &dp)
{
	if (ind >= rack.size())
	{
		return 0;
	}
	if (dp[ind][prev + 1] != -1)
	{
		return dp[ind][prev + 1];
	}
	int not_pick = 0 + sequencer(rack, ind + 1, cur, prev, dp);
	int pick = 0;
	if (prev == -1 || rack[ind] > rack[prev])
	{
		pick = rack[ind] + sequencer(rack, ind + 1, cur + rack[ind], ind, dp);
	}
	return dp[ind][prev + 1] = max(pick, not_pick);
}

int maxIncreasingDumbbellsSumMemoization(vector<int> &rack, int n)
{
	vector<vector<int>> dp(n, vector<int>(n + 1, -1));
	return sequencer(rack, 0, 0, -1, dp);
}

int main()
{
	int n;
	cout << "Enter the number of dumbbells: ";
	cin >> n;

	vector<int> rack(n);
	cout << "Enter the weights of the dumbbells: ";
	for (int i = 0; i < n; i++)
	{
		cin >> rack[i];
	}

	// Naive Recursive Approach
	int resultNaive = maxIncreasingDumbbellsSumNaive(rack, n);
	cout << "Maximum increasing dumbbells sum (Naive Recursive): " << resultNaive << endl;

	// Using Memoization Approach
	int resultMemoization = maxIncreasingDumbbellsSumMemoization(rack, n);
	cout << "Maximum increasing dumbbells sum (Using Memoization): " << resultMemoization << endl;

	return 0;
}

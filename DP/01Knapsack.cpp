#include <iostream>
#include <vector>

using namespace std;

int sequencer(vector<int> &val, vector<int> &wei, int ind, int bag, vector<vector<int>> &dp)
{
	if (ind == 0)
	{
		if (wei[0] <= bag)
			return val[0];
		else
			return 0;
	}

	if (dp[ind][bag] != -1)
		return dp[ind][bag];

	int nottake = 0 + sequencer(val, wei, ind - 1, bag, dp);
	int take = -1;
	if (wei[ind] <= bag)
	{
		take = val[ind] + sequencer(val, wei, ind - 1, bag - wei[ind], dp);
	}

	return dp[ind][bag] = max(nottake, take);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n, vector<int>(w + 1, -1));
	return sequencer(values, weights, n - 1, w, dp);
}

int main()
{
	vector<int> values = {60, 100, 120};
	vector<int> weights = {10, 20, 30};
	int n = values.size();
	int capacity = 50;

	int result = maxProfit(values, weights, n, capacity);
	cout << "Maximum Profit: " << result << endl;

	return 0;
}

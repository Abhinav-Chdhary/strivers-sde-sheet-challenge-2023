//Recurrence relation
int sequencer(vector<int> &rack, int ind, int cur, int prev){
	if(ind>=rack.size()){
		return 0;
	}
	int not_pick = 0+sequencer(rack, ind+1, cur, prev);
	int pick = 0;
	if(rack[ind]>prev){
		pick = rack[ind]+sequencer(rack, ind+1, cur+rack[ind], rack[ind]);
	}
	return max(pick, not_pick);
}
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	return sequencer(rack, 0, 0, -1);
}
//using memoization
int sequencer(vector<int> &rack, int ind, int cur, int prev, vector<vector<int>> &dp){
	if(ind>=rack.size()){
		return 0;
	}
	if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
	int not_pick = 0+sequencer(rack, ind+1, cur, prev, dp);
	int pick = 0;
	if(prev==-1 || rack[ind]>rack[prev]){
		pick = rack[ind]+sequencer(rack, ind+1, cur+rack[ind], ind, dp);
	}
	return dp[ind][prev+1]=max(pick, not_pick);
}
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	vector<vector<int>> dp(n, vector<int>(n+1, -1));
	return sequencer(rack, 0, 0, -1, dp);
}
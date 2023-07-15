//Recursive dp solution
int sequencer(vector<int> &val, vector<int> &wei, int ind, int bag, vector<vector<int>> &dp){
	if(ind == 0){
        if(wei[0] <=bag) return val[0];
        else return 0;
    }
	if(dp[ind][bag]!=-1) return dp[ind][bag];
	int nottake = 0+sequencer(val, wei, ind-1, bag, dp);
	int take = -1;
	if(wei[ind]<=bag){
		take = val[ind]+sequencer(val, wei, ind-1, bag-wei[ind], dp);
	}
	return dp[ind][bag]=max(nottake, take);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n, vector<int>(w+1, -1));
	return sequencer(values, weights, n-1, w, dp);
}
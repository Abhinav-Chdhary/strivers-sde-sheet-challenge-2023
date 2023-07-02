//Recurrence
int maxCost(vector<int> &prices, int ind, int n){
	if(ind==0){
		return n*prices[0];
	}
	int notTake = 0+maxCost(prices, ind-1, n);
	int take = 0;
	if(ind+1<=n){
		take = prices[ind]+maxCost(prices, ind, n-ind-1);
	}
	return max(take, notTake);
}
int cutRod(vector<int> &price, int n)
{
	return maxCost(price, n-1, n);
}
//Memoization
int maxCost(vector<int> &prices, int ind, int n, vector<vector<int>> &dp){
	if(ind==0){
		return n*prices[0];
	}
	if(dp[ind][n]!=-1) return dp[ind][n];
	int notTake = 0+maxCost(prices, ind-1, n, dp);
	int take = 0;
	if(ind+1<=n){
		take = prices[ind]+maxCost(prices, ind, n-ind-1, dp);
	}
	return dp[ind][n] = max(take, notTake);
}
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n, vector<int> (n+1, -1));
	return maxCost(price, n-1, n, dp);
}
//Tabulation
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n,vector<int>(n+1,-1));
    
    for(int i=0; i<=n; i++){
        dp[0][i] = i*price[0];
    }
    
    for(int ind=1; ind<n; ind++){
        for(int length =0; length<=n; length++){
        
             int notTaken = 0 + dp[ind-1][length];
    
             int taken = 0;
             if(ind+1 <= length)
                taken = price[ind] + dp[ind][length-ind-1];
        
             dp[ind][length] = max(notTaken,taken);   
        }
    }
    
    return dp[n-1][n];
}
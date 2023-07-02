//Recurrence
bool findWays(vector<int> &arr, int n, int value, int ind){
    if(value==0){
            return 1;
        }
    if(ind>=n){
        return 0;
    }
    bool pick = 0;
    if(arr[ind]<=value)
        pick = findWays(arr, n, value-arr[ind], ind+1);
    bool notPick = findWays(arr, n, value, ind+1);
    return (pick||notPick);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    //vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return findWays(arr, n, k, 0);
}
//memoization
bool findWays(vector<int> &arr, int n, int value, int ind, vector<vector<int>> &dp){
    if(value==0){
            return 1;
        }
    if(ind>=n){
        return 0;
    }
    if(dp[ind][value]!=-1) return dp[ind][value];
    bool pick = 0;
    if(arr[ind]<=value)
        pick = findWays(arr, n, value-arr[ind], ind+1, dp);
    bool notPick = findWays(arr, n, value, ind+1, dp);
    return dp[ind][value]=(int)(pick||notPick);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return findWays(arr, n, k, 0,dp);
}
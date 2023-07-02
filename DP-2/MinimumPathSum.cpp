//Recurrence relation
//-------------------------------
void traveller(vector<vector<int>> &grid, int i, int j, int curr, int &ans){
  if (i == 0 && j == 0) {
    ans = min(curr+grid[i][j], ans);
    return;
  }
    if(i<0 || j<0){
        return;
    }
    traveller(grid, i, j-1, curr+grid[i][j], ans);
    traveller(grid, i-1, j, curr+grid[i][j], ans);
}
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size(), ans=INT_MAX;
    traveller(grid, n-1, m-1, 0, ans);
    return ans;
}
//Memoization 
//-------------------------------
int traveller(vector<vector<int>> &grid, int i, int j, int curr, int &ans, vector<vector<int>> &dp){
  if (i == 0 && j == 0) {
    return grid[i][j];
  }
  if(i<0 || j<0) return 1e9;
  if(dp[i][j]!=-1) return dp[i][j];
    int left = +grid[i][j]+traveller(grid, i, j-1, curr, ans, dp);
    int up = +grid[i][j]+traveller(grid, i-1, j, curr, ans, dp);
    return dp[i][j]=min(up, left);
}
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size(), ans=INT_MAX;
    vector<vector<int>> dp(n, vector<int> (m, -1));
    return traveller(grid, n-1, m-1, 0, ans, dp);
}
//Tabulation
//-------------------------------
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size(), ans=INT_MAX;
    vector<vector<int>> dp(n, vector<int> (m, 0));
    dp[0][0] = grid[0][0];
    for(int i=1; i<n; i++) dp[i][0] += grid[i][0]+dp[i-1][0];
    for(int i=1; i<m; i++) dp[0][i] += grid[0][i]+dp[0][i-1];
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            dp[i][j] = grid[i][j]+min(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n-1][m-1];
}
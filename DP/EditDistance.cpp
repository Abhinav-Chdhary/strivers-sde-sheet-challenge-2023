//Recursion
//-----------------------------------------------------
int solver(string &w1, string &w2, int i, int j, vector<vector<int>> &dp){
    if(i<0)
        return j+1;
    if(j<0)
        return i+1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(w1[i]==w2[j]){
        return dp[i][j] = 0+solver(w1, w2, i-1, j-1, dp);
    }
    return dp[i][j] = 1+min(solver(w1, w2, i, j-1, dp),
                         min(solver(w1, w2, i-1, j, dp), solver(w1, w2, i-1, j-1, dp)));
}
int editDistance(string str1, string str2)
{
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    return solver(str1, str2, n-1, m-1, dp);
}
//-----------------------------------------------------
//Tabulation
//-----------------------------------------------------
int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for(int i=1; i<=m; i++){
            dp[i][0] = i;
        }
        for(int i=1; i<=n; i++){
            dp[0][i] = i;
        }
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
                }
            }
        }
        return dp[m][n];
    }
//without dp recursive solution O(2^n)
int lcs(string &text1, string &text2, int i, int j){
        if(i<0 || j<0) return 0;
        else if(text1[i]==text2[j])
            return 1+lcs(text1, text2, i-1, j-1, dp);
        else
            return max(lcs(text1, text2, i-1, j), lcs(text1, text2, i, j-1));
    }
//With dp t.c=> O(n*m) s.c=> O(n*m)+O(n*m)->stack and matrix
int lcs(string &text1, string &text2, int i, int j, vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        else if(dp[i][j]!=-1) return dp[i][j];
        else if(text1[i]==text2[j])
            return dp[i][j]=1+lcs(text1, text2, i-1, j-1, dp);
        else
            return dp[i][j]=max(lcs(text1, text2, i-1, j, dp), lcs(text1, text2, i, j-1, dp));
    }
int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        lcs(text1, text2, n1-1, n2-1, dp);
        return dp[n1-1][n2-1];
    }